"""
    Exposes all registerd module as Python Functions (Constructors)
    This serves as hidden factory because it will look like this module
    magicaly imports all module classes.

    Example:
    >>> from sr_registry import klasses
    >>> ahbctrl = klasses.module.AHBCtrl("ahbctrl",
    >>>               rrobin=True
    >>>           )
    >>> print ahbctrl.generics.rrobin.get()
    >>> ahbctrl.ahbOUT(apbctrl.ahb)
"""
def create_module(__name__):
    from builtins import object
    from . import sr_registry
    #from sr_registry import sr_registry
    import abc
    import sys

    class SubModule(object):
        def __init__(self, group):
            self.group = group

        def __dir__(self):
            return [str(name) for name in sr_registry.get_module_names(self.group)]

        def __getattr__(self, klass):
            if klass in list(sr_registry.get_module_names(self.group)):
                group = self.group
                def delegate_new(cls, instance, *args, **kw):
                    obj = sr_registry.create_object_by_name(group, klass, instance)
                    if hasattr(obj, 'generics'):
                        generics = getattr(obj, 'generics')
                        for key, val in kw.items():
                            try:
                                getattr(generics, key).cci_write(str(val))
                            except AttributeError as e:
                                ei = sys.exc_info()
                                raise AttributeError("""USIDelegate '%s', '%s' has no generic '%s'""" % (cls.__name__, instance, key)), None, ei[2].tb_next
                    return obj
                class USIDelegateMeta(abc.ABCMeta):
                    def __init__(cls, name, bases, nmspc):
                        super(USIDelegateMeta, cls).__init__(name, bases, nmspc)
                        cls.__new__ = staticmethod(delegate_new)
                    def __instancecheck__(cls, instance):
                        return sr_registry.is_type(group, klass, instance)
                if sys.version_info >= (3,3):
                    import types
                    return types.new_class(klass, (), {'metaclass': USIDelegateMeta})
                else:
                    return USIDelegateMeta(klass, (), {})
            else:
                return None

    class Module(object):
        def __init__(self, name):
            global __name__
            self.__name__ = __name__ = name

        def __dir__(self):
            return list(tuple(sr_registry.get_group_names())+tuple(['registry']))

        def __getattr__(self, group):
            if group == 'registry':
                return sr_registry
            if group in list(sr_registry.get_group_names()):
                return SubModule(group)
            else:
                return None

    return  Module(__name__)

import sys
sys.modules[__name__] = create_module(__name__)

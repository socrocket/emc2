"""
    Exposes all registerd module as Python Functions (Constructors)
    This serves as hidden factory because it will look like this module
    magicaly imports all module classes.

    Example:
    >>> import sr_registry
    >>> ahbctrl = sr_registry.module.AHBCtrl("ahbctrl",
    >>>               rrobin=True
    >>>           )
    >>> print ahbctrl.generics.rrobin.get()
    >>> ahbctrl.ahbOUT(apbctrl.ahb)

    Or write a service class for a sc_module:
    >>> '''In gaisler/ahbctrl/ahbctrl.py'''
    >>> from sr_registry import USIDelegateBase
    >>> 
    >>> class AHBCtrl(USIDelegateBase):
    >>>     # Defining the sr_registry category in which AHBCtrl is registered
    >>>     self.__usi_group__ = 'module'
    >>>     # Defining the sc_module name
    >>>     self.__usi_class__ = 'AHBCtrl'
    >>> 
    >>>     def __init__(self, *k, **kw):
    >>>         '''Calling the C++ constructor'''
    >>>         super(AHBCtrl, self).__init__(*k, **kw)
    >>>     def print_slaves(self):
    >>>         '''An external service function which will be attached to any object of the systemc type AHBCtrl.'''
    >>>         print 'dooo'

    To use like:
    >>> from gaisler.ahbctrl.ahbctrl import AHBCtrl
    >>> ahbctrl = AHBCtrl("ahbctrl",
    >>>               rrobin=True
    >>>           )
    >>> print ahbctrl.generics.rrobin.get()
    >>> ahbctrl.ahbOUT(apbctrl.ahb)
"""
def create_module(__name__):
    from builtins import object
    from . import sr_registry as api
    from usi import sc_object
    import abc
    import sys

    def delegate_new(cls, instance, *args, **kw):
        obj = api.create_object_by_name(cls.__usi_group__, cls.__usi_class__, instance)
        if hasattr(obj, 'generics'):
            generics = getattr(obj, 'generics')
            for key, val in kw.items():
                param = generics
                path = key.split("__")
                try:
                    for part in path:
                        param = getattr(param, part)
                    param.cci_write(str(val))
                except AttributeError as e:
                    ei = sys.exc_info()
                    raise AttributeError("""USIDelegate '%s', '%s' has no generic '%s'""" % (cls.__name__, instance, key)), None, ei[2].tb_next
        return obj

    class USIDelegateMeta(abc.ABCMeta):
        def __init__(cls, name, bases, nmspc):
            if cls.__usi_class__ != "":
                for item_name, item in cls.__dict__.items():
                    if not item_name.startswith("_"):
                        sc_object.attach("{}.{}".format(cls.__usi_group__, cls.__usi_class__), item_name, item)
            super(USIDelegateMeta, cls).__init__(name, bases, nmspc)
            cls.__new__ = staticmethod(delegate_new)
        def __instancecheck__(cls, instance):
            return api.is_type(cls.__usi_group__, cls.__usi_class__, instance)
    
    if sys.version_info >= (3,3):
        #class USIDelegateBase(metaclass=USIDelegateMeta):
        #    self.__usi_group__ = ""
        #    self.__usi_class__ = ""
        pass
    else:
        class USIDelegateBase(object):
            __metaclass__ = USIDelegateMeta
            __usi_group__ = ""
            __usi_class__ = ""

    class SubModule(object):
        def __init__(self, group):
            self.group = group

        def __dir__(self):
            return [str(name) for name in api.get_module_names(self.group)]

        def __getattr__(self, klass):
            if klass in list(api.get_module_names(self.group)):
                if sys.version_info >= (3,3):
                    import types
                    return types.new_class(klass, (), {
                        'metaclass': USIDelegateMeta,
                        '__usi_group__': self.group,
                        '__usi_class__': klass
                    })
                else:
                    return USIDelegateMeta(klass, (), {
                        '__usi_group__': self.group,
                        '__usi_class__': klass
                    })
            else:
                return None

    class Module(object):
        def __init__(self, name):
            global __name__
            self.__name__ = __name__ = name
            self.USIDelegateMeta = USIDelegateMeta
            self.USIDelegateBase = USIDelegateBase
            self.api = api

        def __dir__(self):
            return list(tuple(api.get_group_names())+tuple(self.__dict__))

        def __getattr__(self, group):
            if group in self.__dict__:
                return self.__dict__[group]
            elif group in list(api.get_group_names()):
                return SubModule(group)
            else:
                return None

    return Module(__name__)

import sys
sys.modules[__name__] = create_module(__name__)

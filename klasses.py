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
from builtins import object
from sr_registry import sr_registry
import types
import abc
import sys

class SubModule(object):
    def __init__(self, group):
        self.group = group
    def __dir__(self):
        return list(sr_registry.get_module_names(self.group))
    def __getattr__(self, klass):
        if klass in list(sr_registry.get_module_names(self.group)):
            group = self.group
            def delegate_new(cls, instance, *args, **kw):
                obj = sr_registry.create_object_by_name(group, klass, instance)
                if "generics" in obj:
                    for key, val in kw:
                        obj.generics[key].set(val)
                return obj
            class USIDelegateMeta(abc.ABCMeta):
                def __init__(cls, name, bases, nmspc):
                    super(USIDelegateMeta, cls).__init__(name, bases, nmspc)
                    cls.__new__ = staticmethod(delegate_new)
                def __instancecheck__(cls, instance):
                    return sr_registry.is_type(group, klass, instance)
            return types.new_class(klass, (), {'metaclass': USIDelegateMeta})
        else:
            return None

class Module(object):
    def __dir__(self):
        return list(sr_registry.get_group_names())
    def __getattr__(self, group):
        if group in list(sr_registry.get_group_names()):
            return SubModule(group)
        else:
            return None

sys.modules[__name__] = Module()

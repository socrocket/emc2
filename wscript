#! /usr/bin/env python
# vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 filetype=python :
top = '..'
REPOSITORY_PATH = "emc2quadcopter"
REPOSITORY_NAME = "emc2 Quadcopter"
REPOSITORY_DESC = "SoCRockets emc2 extensions to simulate a quadcopter"
REPOSITORY_TOOLS = [
]

def build(self):
  self.recurse_all()

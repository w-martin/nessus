#!/usr/bin/env python
#
# File:   MockLayer.h
# Author: Will
# 
# Created on 05 July, 20:30
#
# Licensed under the BSD 2-Clause Licence.
# You may obtain a copy of the license at
# 
#     http://www.opensource.org/licenses/bsd-license.php
# 
# See COPYING for a copy of the License applied to this product.
# 

"""Driver for mocking a class with Google Mock with minimal effort."""

__author__ = 'will.st4@gmail.com (William Martin)'

import sys

## Definitions
# Directories needed
headerDir = "include/nn-simulator/"
mainDir = headerDir + "main/"
testDir = headerDir + "test/"
# gmock script
gmockScript = "gmock-1.6.0/scripts/generator/gmock_gen.py"

if len(sys.argv) > 1:
    source = sys.argv[1]
    

else:
    print("Usage:\n    scripts/mock_class.py header.h\nWhere the header location is relative to include/nn-simulator/main/\n")

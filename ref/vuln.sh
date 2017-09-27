#!/bin/bash
#
# Runs ./ref/vuln with ASLR disabled.
#

LOC="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
exec setarch "$(uname -m)" -R "$LOC/ref/vuln"

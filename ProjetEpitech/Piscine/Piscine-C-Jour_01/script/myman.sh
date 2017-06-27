#!/bin/bash
var_ls="ls^^"
var_pwd="pwd^^"
var_wc="wc^^"
var_cut="cut^^"
var_mkdir="mkdir^^"
var_rm="rm^^"
var_rmdir="rmdir^^"
var_touch="touch^^"
var_chmod="chmod^^"
var_cp="cp^^"
var_mv="mv^^"
var_less="less^^"
if ${1^^} == ${var_ls}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_pwd}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_wc^^}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_cut}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_mkdir}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_rm}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_rmdir}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_touch}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_chmod}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_cp}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_mv}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
elif {1^^} == ${var_less}
then sed -n "/${1^^}(1)/,/${1^^}(1)/p" $1 $2
else echo "commande non trouvée dans le coffre-fort"
fi

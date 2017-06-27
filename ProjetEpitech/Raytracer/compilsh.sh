clean()
{
    SEARCH='.'
    if [ ${1} ]
    then
        SEARCH=${1}
    fi
    find ${SEARCH} \( -name "*~" -or -name ".*~" \) -exec rm -fv {} \;
}
clean
make re
make clean

output_d="./output"
data_d="./data"
view_file () {
    filename="$1"    
    echo -n '<'
    #cat "$filename"
    #cat "$filename"
    echo -n $(cat "$filename")
    echo '>'
}

report_case () {
    echo -n '    Input: '
    view_file "$data_d/$test_case.in"
    echo -n '    Expected: '
    view_file "$data_d/$test_case.out"
    echo -n '    Received: '
    view_file "$output_d/$test_case.out"
}

init () {
    if [ ! -d "$output_d" ]; then
        mkdir "$output_d"
    fi 
} 

main () {
    cases=0

    fails=0

    errors=0
    failstr=''

    errorstr=''
    for input in "$data_d"/*.in; do 
        if [ -f "$input" ]; then
            cases=$(( cases + 1 ))

            test_case=`basename "$input"` 
            #echo "$test_case"
            test_case=${test_case%.in}
            #echo "$test_case"

            echo "Check $test_case ... "
            ./a < "$data_d/$test_case.in"> "$output_d/$test_case.out"
            diff -w "$data_d/$test_case.out" "$output_d/$test_case.out"
            retcode=$?

            if [ $retcode -eq 0 ]; then
                echo 'Passed'
                report_case "$test_case"

            elif [ $retcode -eq 1 ]; then
                fails=$(( fails + 1 ))
                failstr="$failstr $test_case"
                echo 'Failed'
                report_case "$test_case"

            else 
                errors=$(( errors + 1 ))
                errorstr="$errorstr $test_case"
                echo 'Error'
                report_case "$test_case"
            fi
        fi
    done
    echo "$cases cases checked, $fails failed, $errors errored"
    if [ $fails -gt 0 ]; then
        echo "Failed cases:${failstr}"
    fi
    if [ $errors -gt 0 ]; then
        echo "Errored cases:${errorstr}"
    fi

}

init
main

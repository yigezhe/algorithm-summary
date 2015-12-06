int read_int(int *first) {
    //这里我只读取正整数！
    char get;
    *first=0;
    while(1) {
        get=getchar();
        if ((get>='0') && (get<='9')) {
            *first=(*first)*10+get-'0';
        } else {
            break;
        }
    }
    return 1;
}

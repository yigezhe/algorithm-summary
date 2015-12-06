int read_int(int *first) {
    char ch,r=0,negative=0;
    //r=0表示没有读取到数字之前！
    //r=1表示正在读取数字！
    //我必须看看这个代码在c中能不能编译通过！
    *first=0;
    for(;;) {
        ch=getchar();
        if ((ch<0) && (!r))
            return 0 ;
	//这里允许两虚出现负号！//这个是需要改进的地方！
        if ((ch=='-') && (!r))
            negative=1;
        //只要继续是整数就接收！
        else if ((ch>='0') && (ch<='9'))
            *first=(*first)*10+ch-'0',r=1;
        else if (r)
            break;
    }
    if (negative)
        *first=-(*first);
    return 1;
}

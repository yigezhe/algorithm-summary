int is_letter(char a) {
    if(a>='a' && a<='z') {
        return 1;
    }
    if(a>='A' && a<='Z') {
        return 1;
    }
    return 0;
}

string longDiv(string &str, int div) {
    string ret = "";

    int indx = 0, curr = str[indx] - '0';
    while(curr<div) {
        curr = curr * 10 + (str[++indx]-'0');
    }

    int sz = str.size();
    while(indx<sz) {
        ret += ((curr/div)+'0');
        curr = (curr%div)*10 + (str[++indx]-'0');
    }

    if(ret.size()==0) {
        return "0";
    }

    return ret;
}

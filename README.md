# VigenereCipher
维吉尼亚密码

假设明文为m=m1 m2 m3 ... mh，
密钥k= k1 k2 k3 ... kt, 一般t < h， 
密文序列为c = c1 c2 c3 ... ch
则维吉尼亚密码加密公式为
ci = (mi + k(i mod t)) mod 26

即密钥的第i个字母模26加到了明文的第i个字母，紧接着是第i+1个字母，依次类推，直到h个明文字母处理完毕。

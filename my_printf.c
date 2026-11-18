#include <unistd.h>
#include <stdarg.h>
int my_putchar(char c){
    write(1,&c,1);
    return 1;
}
int my_char(va_list args){
    char c;
    c=(char)va_arg(args,int);
    my_putchar(c);
    return 1;
}
int my_str(va_list args){
    char *str;
    str=va_arg(args,char*);
    int i=0;
    if(str==NULL){
        my_putchar('(');
        my_putchar('n');
        my_putchar('u');
        my_putchar('l');
        my_putchar('l');
        my_putchar(')');
        return 6;
    }
    while(str[i]!='\0'){
        my_putchar(str[i]);
        i++;
    }
    return i;
}
int my_int_number(long n){
    int count=0;
    if(n>=10)
        count+=my_int_number(n/10);
    my_putchar((n%10)+'0');
    count++;
    return count;
}
int my_int(va_list args){
    long n;
    int count=0;
    n=va_arg(args,int);
    if(n<0){
        my_putchar('-');
        count++;
        n=-n;
    }
    count+=my_int_number(n);
    return count;
}
int my_ptr_number(unsigned long n){
    char *hex;
    int  count;
    hex="0123456789abcdef";
    count=0;
    if(n>=16){
        count+=my_ptr_number(n/16);
    }
    my_putchar(hex[n%16]);
    count++;
    return (count);
}
int my_ptr(va_list args){
    void *ptr;
    ptr=va_arg(args,void*);
    if(ptr==NULL){
        my_putchar('(');
        my_putchar('n');
        my_putchar('i');
        my_putchar('l');
        my_putchar(')');
        return 5;
    }
    unsigned long n;
    int count=0;
    my_putchar('0');
    my_putchar('x');
    n=(unsigned long)ptr;
    count=count+2+my_ptr_number(n);
    return count;
}
int my_hex_number(unsigned long n){
    char *hex;
    int  count=0;
    hex="0123456789ABCDEF";
    if(n>=16){
        count+=my_hex_number(n/16);
    }
    my_putchar(hex[n%16]);
    count++;
    return count;
}
int my_hex(va_list args){
    unsigned long n;
    n=va_arg(args,unsigned int);
    return my_hex_number(n);
}
int my_octal_number(unsigned long n){
    char *hex;
    int  count=0;
    hex="01234567";
    if(n>=8){
        count+=my_octal_number(n/8);
    }
    my_putchar(hex[n%8]);
    count++;
    return count;
}
int my_octal(va_list args){
    unsigned long n;
    n=va_arg(args,unsigned int);
    return my_octal_number(n);
}
int my_decimal_number(unsigned long n){
    int count=0;
    if(n>=10)
        count+=my_decimal_number(n/10);
    my_putchar((n%10)+'0');
    count++;
    return count;
}
int my_decimal(va_list args){
    unsigned long n;
    n=va_arg(args,unsigned int);
    return my_decimal_number(n);
}
int my_printf(char * restrict format, ...){
    va_list args;
    int i=0;
    int count=0;
    va_start(args,format);
    while(format[i]!='\0'){
        if(format[i]=='%'){
            i++;
            if (format[i]=='c'){
                count+=my_char(args);
            }
            else if(format[i]=='s'){
                count+=my_str(args);
            }
            else if(format[i]=='d'){
                count+=my_int(args);
            }
            else if(format[i]=='p'){
                count+=my_ptr(args);
            }
            else if(format[i]=='u'){
                count+=my_decimal(args);
            }
            else if(format[i]=='o'){
                count+=my_octal(args);
            }
            else if(format[i]=='x'){
                count+=my_hex(args);
            }
            else if(format[i]=='%'){
                count+=my_putchar('%');
            }
        }
        else{
            count+=my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return count;
}

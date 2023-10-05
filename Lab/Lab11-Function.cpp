/*
    จงเขียนฟังก์ชันในการตรวจสอบตัวเลขที่ผู้ใช้ป้อนเข้ามา ว่าเป็นตัวเลขที่เป็นอาร์มสตรองหรือไม่ หากใช่ให้แสดงคำว่า Pass หากไม่ใช่แสดงคำว่า Not Pass
    
    หมายเหตุ: ตัวเลขอาร์มสตรอง คือ ตัวเลขที่ผลรวมของเลขยกกำลังของจำนวนหลัก เช่น
    153 เป็นตัวเลขอาร์มสตรอง เพราะ 153 มีทั้งหมด 3 หลัก จึงมีค่าเท่ากับ = 1^3 +  5^3 +  3^3 (โดยที่เครื่องหมาย ^ หมายถึงเลขยกกำลัง)
    370 = 3^3 + 7^3 + 0^3

    Test Case:
        Enter Number:
            153
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            370
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            372
    Output:
        Not Pass.
*/

#include <stdio.h>

int cal( int number ){

    int unit = 0 ;
    //หาจำนวนหลัก ของเลขที่กรอกกมา
    if ( number >= 1000 ) {
        unit = 4 ;
    }
    else if (number >= 100) {
        unit = 3 ;
    }
    else if (number >= 10) {
        unit = 2 ;
    }
    // หาตัวเลขในแต่ละหน่วย แยกเป็นหลัก ๆ
    int thousand = number / 1000 ;
    int hundred  = ( number - thousand * 1000) / 100 ; // 1
    int ten = ( number - ( ( thousand * 1000 ) + ( hundred * 100 ) ) ) / 10 ;// 5
    int one = ( number - ( ( thousand * 1000 ) + ( hundred * 100 ) + ( ten * 10 ) ) );// 3

    int thousand_power = thousand , hundred_power = hundred , ten_power = ten , one_power = one ;

    for (int i = 1; i < unit ; i++) {

        thousand_power = thousand_power * thousand ;

        hundred_power = hundred_power * hundred ;

        ten_power = ten_power * ten ;

        one_power = one_power  * one ;

    }
    
    return thousand_power + hundred_power + ten_power + one_power ;

}

int main() {

    int number ;

    printf( "Enter Number:\n" ) ;
    scanf( "%d",&number ) ;
    int asw = cal(number);
    // printf ( "%d",cal( number ) ) ;
    if ( number == asw ) {
        printf( "Pass." ) ;
    }
    else if ( number != asw ) {
       printf( "Not Pass." ) ;
    }

    return 0 ;
}//end main function
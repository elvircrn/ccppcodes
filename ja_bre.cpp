#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MaxLen = 200;

class BigNumber
{
public :

    int Number[MaxLen];

    int Len;

    BigNumber ( void )
    {
        memset ( Number, 0, sizeof ( Number ) );

        Len = 1;
    }

    BigNumber ( int Num )
    {
        memset ( Number, 0, sizeof ( Number ) );

        Len = 0;

        if ( ! Num ) Len++;

        while ( Num )
        {
            Number[Len++] = Num % 10;

            Num /= 10;
        }
    }

    BigNumber ( char Str[MaxLen] )
    {
        memset ( Number, 0, sizeof ( Number ) );

        Len = strlen ( Str );

        for ( int i = 0; i < Len; i++ ) Number[i] = ( int ) ( Str[Len - i - 1] - '0' );
    }

    void Print ( void )
    {
        for ( int i = Len - 1; i >= 0; i-- ) printf ( "%d", Number[i] );

        //printf ( "\n" );
    }

    BigNumber operator + ( const BigNumber & BigNum )
    {
        int Carry = 0;

        BigNumber Answer ( * this );

        if ( BigNum.Len > Answer.Len ) Answer.Len = BigNum.Len;

        for ( int i = 0; i < Answer.Len; i++ )
        {
            Answer.Number[i] += ( BigNum.Number[i] + Carry );

            Carry = Answer.Number[i] / 10;

            Answer.Number[i] %= 10;
        }

        if ( Carry != 0 )
        {
            Answer.Number[Answer.Len] = Carry;

            Answer.Len++;
        }

        return Answer;
    }

    BigNumber operator - ( const BigNumber & BigNum )
    {
        BigNumber Answer ( * this );

        int Carry = 0;

        for ( int i = 0; i < Answer.Len; i++ )
        {
            Answer.Number[i] = Answer.Number[i] - BigNum.Number[i] - Carry;

            if ( Answer.Number[i] < 0 )
            {
                Answer.Number[i] = Answer.Number[i] + 10;

                Carry = 1;
            }
            else Carry = 0;
        }

        while ( ( ! Answer.Number[Answer.Len - 1] ) && ( Answer.Len > 1 ) ) Answer.Len--;

        return Answer;
    }

    BigNumber operator * ( const BigNumber & BigNum )
    {
        BigNumber Answer ( 0 );

        for ( int i = 0; i < Len; i++ )
        {
            int Carry = 0;

            for ( int j = 0; j < BigNum.Len; j++ )
            {
                int Temp = Answer.Number[i + j] + Number[i] * BigNum.Number[j] + Carry;

                Answer.Number[i + j] = Temp % 10;

                Carry = Temp / 10;
            }

            Answer.Number[i + BigNum.Len] = Carry;
        }

        Answer.Len = Len + BigNum.Len;

        while ( ( ! Answer.Number[Answer.Len - 1] ) && ( Answer.Len > 1 ) ) Answer.Len--;

        return Answer;
    }

    BigNumber operator / ( int Num )
    {
        BigNumber Answer ( 0 );

        int Remain = 0;

        for ( int i = Len - 1; i >= 0; i-- )
        {
            Remain = Remain * 10 + Number[i];

            Answer.Number[i] = Remain / Num;

            Remain = Remain % Num;
        }

        Answer.Len = Len;

        while ( ( ! Answer.Number[Answer.Len - 1] ) && ( Answer.Len > 1 ) ) Answer.Len--;

        return Answer;
    }

    BigNumber operator / ( BigNumber Number )
    {
        BigNumber L = BigNumber ( 1 );
        BigNumber R = ( * this );
        BigNumber M;
        BigNumber One ( 1 );

        while ( L <= R )
        {
            M = ( L + R ) / 2;

            BigNumber Z = M * Number;

            if ( Z == ( * this ) ) return M;

            if ( Z > ( * this ) ) R = M - One;
            else L = M + One;
        }

        if ( M * Number > ( * this ) ) M = M - 1;

        return M;
    }

    BigNumber operator ^ ( BigNumber Power )
    {
        BigNumber Answer ( 1 ), Multiply = ( * this ), Zero ( 0 );

        while ( Power != Zero )
        {
            if ( Power.Number[0] % 2 ) Answer = Answer * Multiply;

            Power = Power / 2;

            Multiply = Multiply * Multiply;
        }

        return Answer;
    }

    BigNumber operator % ( BigNumber Modulo )
    {
        BigNumber Answer = ( * this );

        BigNumber Quotient = Answer / Modulo;

        return Answer - Quotient * Modulo;
    }

    int operator < ( const BigNumber & BigNum )
    {
        if ( Len < BigNum.Len ) return 1;

        if ( Len > BigNum.Len ) return 0;

        int i;

        for ( i = Len - 1; i >= 0; i-- ) if ( Number[i] != BigNum.Number[i] ) break;

        if ( i == -1 ) return 0;

        if ( Number[i] < BigNum.Number[i] ) return 1;

        return 0;
    }

    int operator == ( const BigNumber & BigNum )
    {
        if ( Len != BigNum.Len ) return 0;

        for ( int i = Len - 1; i >= 0; i-- ) if ( Number[i] != BigNum.Number[i] ) return 0;

        return 1;
    }

    int operator != ( const BigNumber & BigNum )
    {
        return ! ( ( * this ) == BigNum );
    }

    int operator > ( const BigNumber & BigNum )
    {
        if ( ( * this ) < BigNum ) return 0;

        if ( ( * this ) == BigNum ) return 0;

        return 1;
    }

    int operator <= ( const BigNumber & BigNum )
    {
        if ( ( ( * this ) < BigNum ) || ( ( * this ) == BigNum ) ) return true;
        else return false;
    }

    int operator >= ( const BigNumber & BigNum )
    {
        if ( ( ( * this ) > BigNum ) || ( ( * this ) == BigNum ) ) return true;
        else return false;
    }
};

BigNumber a[2][402];

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);
        memset(a, 0, sizeof a);
    if (K == 0) {printf ("1\n"); return 0;}
    a[0][K] = BigNumber(1);

    a [0] [K] = a [0] [K + 1] = a [0] [K + 2] = BigNumber (1);

    for( int i = 1; i <= N; i++ )
    {


        for( int j = 1; j <= 2 * K + 1; j++ )
            if( i % 2 == 0 )
                a[0][j] = a[1][j - 1] + a[1][j] + a[1][j + 1];
            else
                a[1][j] = a[0][j - 1] + a[0][j] + a[0][j + 1];
    }

    BigNumber r(0);

    for( int i = 0; i <= 2 * K + 1; i++ )
        r = r + a[((N % 2) + 1) % 2][i];

    r.Print();

    return 0;
}

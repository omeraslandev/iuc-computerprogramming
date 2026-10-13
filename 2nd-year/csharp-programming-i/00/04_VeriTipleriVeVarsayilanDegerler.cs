using System;

namespace DersNotlari
{
    public static class VeriTipleriVeVarsayilanDegerler
    {
        public static void Calistir()
        {
            // 'new T()' kullanımı, ilgili değer tipinin (Value Type) varsayılan (default) değerini atar.
            int intDeneme = new int();             // Default: 0
            bool boolDeneme = new bool();         // Default: false
            byte byteDeneme = new byte();         // Default: 0
            char charDeneme = new char();         // Default: '\0' (null karakter)
            decimal decimalDeneme = new decimal();// Default: 0
            double doubleDeneme = new double();   // Default: 0
            float floatDeneme = new float();       // Default: 0

            Console.WriteLine($"int default    : {intDeneme}");
            Console.WriteLine($"bool default   : {boolDeneme}");
            Console.WriteLine($"byte default   : {byteDeneme}");
            Console.WriteLine($"char default   : '{charDeneme}' (Boş/Null Karakter)");
            Console.WriteLine($"decimal default: {decimalDeneme}");
            Console.WriteLine($"double default : {doubleDeneme}");
            Console.WriteLine($"float default  : {floatDeneme}");

            // Modern C#'ta varsayılan değerler için alternatif yöntem:
            int modernDefault = default;
            Console.WriteLine($"default keyword: {modernDefault}");
        }
    }
}
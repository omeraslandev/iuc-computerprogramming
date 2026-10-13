using System;

namespace DersNotlari
{
    public static class SabitlerConst
    {
        public static void Calistir()
        {
            // const: Değeri bir kez atanır ve çalışma zamanında (runtime) asla değiştirilemez.
            const int constDeneme = 0;
            Console.WriteLine($"Sabit değer: {constDeneme}");

            // constDeneme = 2; // HATA: CS0131 The left-hand side of an assignment must be a variable, property or indexer

            int denemeDegisken3 = 3;
            int denemeDegisken4 = 4;

            // const değişkenlerin değeri 'Derleme Zamanında' (Compile-time) belli olmalıdır.
            // Çalışma zamanında hesaplanacak dinamik değişkenlerin toplamı const bir değişkene atanamaz.
            
            // const int constDeneme2 = denemeDegisken3 + denemeDegisken4; // HATA!
            
            // Ancak iki sabit değerin toplamı atabilir:
            const int constDeneme3 = 10 + 20; // Geçerli!
            Console.WriteLine($"Sabitlerin toplamı: {constDeneme3}");
        }
    }
}
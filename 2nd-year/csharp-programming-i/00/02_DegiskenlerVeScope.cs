using System;

namespace DersNotlari
{
    public static class DegiskenlerVeScope
    {
        // Sınıf seviyesindeki değişken (Field)
        static int sinifSeviyesiDegisken = 100;

        public static void Calistir()
        {
            int denemeDegisken = 1;
            Console.WriteLine($"Değişken değeri: {denemeDegisken}");

            int denemeDegisken2 = 2;
            {
                // İç Scope (Blok): denemeDegisken2'ye burada erişilebilir.
                // Çünkü bu blok, Calistir() metodunun (üst scope) altındadır.
                Console.WriteLine($"İç bloktan erişim: {denemeDegisken2}");
                Console.WriteLine($"Sınıf seviyesinden erişim: {sinifSeviyesiDegisken}");
            }

            // Aynı satırda birden fazla değişken tanımlama:
            int denemeDegisken3 = 3, denemeDegisken4 = 4;
            Console.WriteLine($"Aynı satırda tanımlananlar: {denemeDegisken3}, {denemeDegisken4}");

            // --- HATA SENARYOLARI ---
            // 1. Değeri atanmamış değişken kullanımı:
            // int denemeDegisken5;
            // Console.WriteLine(denemeDegisken5); // HATA: CS0165 Use of unassigned local variable 'denemeDegisken5'

            // 2. Scope dışı erişim:
            // Console.WriteLine(icBlokDegiskeni); // İç blokta tanımlanan bir değişkene dışarıdan erişilemez!
        }

        public static void BaskaMetot()
        {
            // denemeDegisken değişkenine burada erişilemez! Çünkü Calistir() metodunun scope'u dışındadır.
            // Ancak sınıf seviyesindeki değişkene erişilebilir:
            Console.WriteLine(sinifSeviyesiDegisken);
        }
    }
}
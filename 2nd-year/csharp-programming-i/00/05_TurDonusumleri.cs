using System;

namespace DersNotlari
{
    public static class TurDonusumleri
    {
        public static void Calistir()
        {
            Console.WriteLine("=== 1. BİLİNÇSİZ (IMPLICIT) TÜR DÖNÜŞÜMÜ ===");
            // Veri kaybı riski olmayan durumlarda C# dönüşümü otomatik yapar.
            // Küçük veri tipi -> Büyük veri tipi

            byte kucukSayi = 42;
            int buyukSayi = kucukSayi; // Otomatik dönüşüm (byte -> int)
            double ondalikliSayi = buyukSayi; // Otomatik dönüşüm (int -> double)

            Console.WriteLine($"Byte Değer   : {kucukSayi}");
            Console.WriteLine($"Int'e Aktarıldı: {buyukSayi}");
            Console.WriteLine($"Double'a Aktarıldı: {ondalikliSayi}");


            Console.WriteLine("\n=== 2. BİLİNÇLİ (EXPLICIT) TÜR DÖNÜŞÜMÜ ===");
            // Veri kaybı ihtimali olan durumlarda geliştiricinin açıkça belirtmesi gerekir.
            // Büyük veri tipi -> Küçük veri tipi

            // A. Type Casting (Döküm) İle Dönüşüm
            double pi = 3.14159;
            int tamSayiPi = (int)pi; // Ondalık kısım atılır (Veri kaybı yaşanır!)
            Console.WriteLine($"Casting (double -> int): {tamSayiPi}"); // Çıktı: 3

            long genisSayi = 500;
            byte darSayi = (byte)genisSayi; // Byte maks 255 alabilir, taşma (overflow) yaşanır!
            Console.WriteLine($"Casting Taşma Örneği (500 -> byte): {darSayi}");

            // B. Convert Sınıfı İle Dönüşüm
            string metinselSayi = "123";
            int donusturulenSayi = Convert.ToInt32(metinselSayi);
            Console.WriteLine($"Convert.ToInt32(string -> int): {donusturulenSayi + 10}"); // Çıktı: 133

            // C. Parse Metodu İle Dönüşüm (Özellikle string -> sayı dönüşümlerinde)
            string fiyatText = "49.99";
            // Not: Sisteminizin bölgesel ayarına (Culture) göre nokta/virgül fark edebilir.
            double fiyat = double.Parse(fiyatText, System.Globalization.CultureInfo.InvariantCulture);
            Console.WriteLine($"double.Parse(string -> double): {fiyat}");
        }
    }
}
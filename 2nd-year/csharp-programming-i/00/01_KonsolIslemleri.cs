using System;

namespace DersNotlari
{
    public static class KonsolIslemleri
    {
        public static void Calistir()
        {
            // .Clear() bir metottur (method). Konsolu temizler.
            Console.Clear();

            // .BackgroundColor bir özelliktir (property). Değer ataması yapılır.
            Console.BackgroundColor = ConsoleColor.DarkBlue;

            // .WriteLine() metodu metni yazar ve imleci bir alt satıra indirir.
            Console.WriteLine("Hello!");
            Console.WriteLine("WriteLine Deneme");

            // .Write() metodu metni yazar ancak imleci aynı satırda tutar.
            Console.Write("Write Deneme - ");
            Console.WriteLine("Bu yazı aynı satırın devamına gelir.");

            Console.WriteLine("\nBir sayı veya karakter giriniz: ");

            // .ReadLine() kullanıcı Enter'a basana kadar tüm satırı string olarak okur. (C'deki scanf gibi)
            Console.ReadLine();

            // .Read() klavyeden basılan ilk karakterin ASCII sayısal değerini okur.
            Console.Read();

            // Konsol rengini varsayılana sıfırlayalım
            Console.ResetColor();
        }
    }
}
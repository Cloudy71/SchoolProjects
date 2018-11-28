/*
  User: Cloudy
  Date: 28-Nov-18
  Time: 21:09
*/

package cz.kozusznik.pl1;

import cz.kozusznik.pl1.lab10.Book;
import cz.kozusznik.pl1.lab10.ImgFinder;
import cz.kozusznik.pl1.lab10.PalindromSearch;

public class Main {
    public static void main(String[] args) {
        System.out.println("=========PALINDROMES=========");
        Book book = new Book();
        for (String palindrome : PalindromSearch.findAll(book.toString())) {
            System.out.println(palindrome);
        }

        System.out.println("===========IMAGES============");
        for (String s : ImgFinder.getAll(
                "https://wonderfulengineering.com/50-nature-wallpapers-hd-for-free-download/")) {
            System.out.println(s);
        }
    }
}

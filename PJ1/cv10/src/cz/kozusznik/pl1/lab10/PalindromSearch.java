/*
  User: Cloudy
  Date: 28-Nov-18
  Time: 21:01
*/

package cz.kozusznik.pl1.lab10;

import java.util.LinkedList;
import java.util.List;

public class PalindromSearch {
    public static String[] findAll(String sequence) {
        List<String> palindromes = new LinkedList<>();
        String[] words = sequence.split(" ");
        for (String word : words) {
            word = word.trim();
            if (word.length() <= 1) continue;

            int partLen = word.length() / 2;
            if (word.substring(0, partLen)
                    .equals(new StringBuffer(word.substring(word.length() - partLen)).reverse().toString())) {
                palindromes.add(word);
            }
        }

        return palindromes.toArray(new String[palindromes.size()]);
    }
}

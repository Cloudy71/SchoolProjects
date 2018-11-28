/*
  User: Cloudy
  Date: 28-Nov-18
  Time: 21:17
*/

package cz.kozusznik.pl1.lab10;

import cz.kozusznik.pl1.utils.IORoutines;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ImgFinder {
    public static String[] getAll(String url) {
        List<Object[]> imgs = new LinkedList<>();

        String web = IORoutines.readPage(url);
        Pattern pattern = Pattern.compile("(?:<img).*?alt=(\"(?:\\w|\\s)*wallpapers(?:\\w|\\s)*\").*?\\/>");
        Matcher matcher = pattern.matcher(web);

        while (matcher.find()) {
            String match = matcher.group();
            String src = match.substring(match.indexOf("src=\"") + 5, match.indexOf("\"", match.indexOf("src=\"") + 5));
            int w = 0, h = 0;
            if (match.contains("width=\"")) {
                w = Integer.parseInt(match.substring(match.indexOf("width=\"") + 7,
                                                     match.indexOf("\"", match.indexOf("width=\"") + 7)));
            }
            if (match.contains("height=\"")) {
                h = Integer.parseInt(match.substring(match.indexOf("height=\"") + 8,
                                                     match.indexOf("\"", match.indexOf("height=\"") + 8)));
            }

            imgs.add(new Object[] {src, w, h});
        }

        imgs.sort((o1, o2) -> {
            int s1 = (int) o1[1] * (int) o1[2];
            int s2 = (int) o2[1] * (int) o2[2];
            return Integer.compare(s1, s2);
        });

        List<String> urls = new LinkedList<>();
        for (int i = 0; i < imgs.size(); i++) {
            urls.add((String) imgs.get(i)[0]);
        }

        Collections.sort(urls);

        return urls.toArray(new String[urls.size()]);
    }
}

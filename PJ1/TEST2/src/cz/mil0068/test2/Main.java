package cz.mil0068.test2;

/*
 * User: MIL0068
 * Date: 20.12.2018
 * Time: 16:29
 */

import java.io.*;
import java.net.URL;
import java.util.zip.GZIPOutputStream;

public class Main {
    public static void main(String args[]) {
        OsobniAuto osobniAuto = new OsobniAuto("nejaky typ", 4);

        for (String s : new PevnyBalikSlov().vratSlovaPodleSouhlasek()) {
            System.out.println(s);
        }

        saveWebContent();

        Pair<OsobniAuto, Integer> autoPair = new Pair<>(osobniAuto, osobniAuto.getPocetOsob());
    }

    public static void saveWebContent() {
        try {
            StringBuilder stringBuilder = new StringBuilder();
            URL url = new URL("https://docs.oracle.com/javase/tutorial/");
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(url.openStream()));
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                stringBuilder.append(line);
            }
            bufferedReader.close();
            Writer writer = new OutputStreamWriter(new GZIPOutputStream(new FileOutputStream("out.html.gz")), "UTF-8");
            writer.write(stringBuilder.toString());
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

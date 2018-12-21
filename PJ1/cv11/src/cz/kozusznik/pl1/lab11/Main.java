package cz.kozusznik.pl1.lab11;

import java.io.*;
import java.nio.charset.Charset;
import java.util.zip.GZIPOutputStream;
import java.util.zip.ZipInputStream;

public class Main {
    private final static String FILE_NAME  = "res/Faust-Goethe.txt.zip";
    private final static String FINAL_NAME = "res/Faust-Goethe.txt.gz";

    public static void main(String[] args) throws IOException {
        zipToGZIP();
    }

    public static void zipToGZIP() throws IOException {
        ZipInputStream zipInputStream = new ZipInputStream(new FileInputStream(FILE_NAME));
        BufferedReader bufferedReader =
                new BufferedReader(new InputStreamReader(zipInputStream, Charset.forName("utf-8")));
        PrintWriter printWriter =
                new PrintWriter(new OutputStreamWriter(new GZIPOutputStream(new FileOutputStream(FINAL_NAME)),
                                                       Charset.forName("windows-1250")));
        zipInputStream.getNextEntry();
        int row = 0;
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            printWriter.printf("%d;%d;%s" + System.getProperty("line.separator"), row++, line.length(), line);
        }
        printWriter.close();
        bufferedReader.close();
        zipInputStream.close();
    }
}

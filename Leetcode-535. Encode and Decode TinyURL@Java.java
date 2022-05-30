public class Codec {
    
    private Map<String, String> lib = new HashMap<>();
    private Random random = new Random();
    
    private static final String BASE = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        String res = lib.get(longUrl);
        if (res != null) {
            return res;
        }
        else {
            String shortUrl = generateRandom();
            while (lib.containsKey(shortUrl)) {
                shortUrl = generateRandom();
            }
            
            lib.put(longUrl, shortUrl);
            lib.put(shortUrl, longUrl);

            return shortUrl;
        }
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return lib.get(shortUrl);
    }
    
    private String generateRandom() {
        String result = "http://tinyurl.com/";
        int len = BASE.length();
        for (int i = 0; i < 6; i++) {
            result += BASE.charAt(random.nextInt(len));
        }
        return result;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));

class RansomNote {
    public boolean canConstruct(String ransom, String magazine) {
        if (magazine.length() < ransom.length())
            return false;
        int caps[] = new int[26];
        for (char c : ransom.toCharArray()) {
            int index = magazine.indexOf(c, caps[c - 'a']);
            if (index == -1)
                return false;
            caps[c - 97] = index + 1;
        }
        return true;
    }
}
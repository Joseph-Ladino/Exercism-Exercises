import java.util.List;

class BinarySearch {
    List<Integer> list;
    
    public int indexOf(int value) throws ValueNotFoundException {

        if(list.size() == 0) throw new ValueNotFoundException("Value not in array");

        int start = 0, end = list.size() - 1, key, keyVal;

        while(true) {
            key = start + (end - start) / 2;
            keyVal = list.get(key);

            if(value == keyVal)
                return key;
            else if(key == start)
                throw new ValueNotFoundException("Value not in array");
            else if(value < keyVal)
                end = key;
            else
                start = key + 1;
            
        }
    }

    public BinarySearch(List<Integer> l) {
        list = l;
    }
}
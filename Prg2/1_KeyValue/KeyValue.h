#ifndef CLASS_KEYVALUE

#define CLASS_KEYVALUE

class KeyValue {
private:
    int _key;
    double _value;
    KeyValue* _next;
public:
    KeyValue(int k, double v);
    ~KeyValue();
    int getKey();
    double getValue();
    KeyValue* getNext();
    void createNext(int k, double v);
    bool hasNext();
};

#endif


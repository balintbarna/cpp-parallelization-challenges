template <typename V, typename I, typename P>
class LambdaIterable {
public:
    explicit LambdaIterable(V value, I increment, P first, P last)
        : value(value), increment(increment), first(first), last(last) {}

    class iterator {
    public:
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;

        explicit iterator(V value, I increment, P position)
            : value(value), increment(increment), position(position) {}

        auto operator*() const {
            return value(position);
        }

        iterator& operator++() {
            position = increment(position);
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& other) const {
            return position == other.position;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

    private:
        V value;
        I increment;
        P position;
    };

    iterator begin() const {
        return iterator(value, increment, first);
    }

    iterator end() const {
        return iterator(value, increment, last);
    }

private:
    V value;
    I increment;
    P first, last;
};

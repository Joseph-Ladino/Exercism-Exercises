#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <vector>
#include <iterator>

namespace binary_search_tree {
    template <typename T>
    struct binary_tree {

        using tree = binary_tree<T>;
        using tree_ptr = std::unique_ptr<binary_tree<T>>;

        struct iterator {
            using iterator_category = std::input_iterator_tag;
            using value_type = binary_tree<T>;
            using pointer = binary_tree<T>*;
            using const_ref = const T&;

            pointer tp = nullptr;
            T val = T();

            bool operator==(iterator other) const { return this->tp == other.tp; }
            bool operator!=(iterator other) const { return this->tp != other.tp; }

            void operator++() {
                auto next = this->tp->next();
                this->tp = next;
                if (this->tp) val = tp->data();
            }

            const_ref operator*() { return val; }

            iterator() { tp = nullptr; }
            iterator(pointer _tp) : tp(_tp) { if (tp) val = tp->data(); }
            iterator(const iterator& o) : tp(o.tp) { if (tp) val = o.tp->data(); }
        };

        const iterator begin() { return iterator(least()); }
        const iterator end() { return iterator(); }

        T d;

        size_t size = 0;

        tree* p = nullptr;
        tree_ptr l;
        tree_ptr r;

        tree_ptr& left() { return l; }
        tree_ptr& right() { return r; }

        tree* least() {
            if (l) return l->least();
            else return this;
        }

        tree* most() {
            if (r) return r->most();
            else return this;
        }

        tree* root() {
            if (p != nullptr) return p->root();
            else return this;
        }

        tree* next(bool lp = false) {
            if (r && !lp) return r->least();
            else if (!p) return p;
            else if (this == p->l.get()) return p;
            else return p->next(true);
        }

        T data() { return d; }

        void insert(T _d) {
            auto& c = _d <= d ? l : r;

            if (c) c->insert(_d);
            else {
                c = tree_ptr(new tree(_d));
                c->p = this;
            }
            size++;
        }

        binary_tree<T>(T _d) : d(_d), size(1) {}
        binary_tree<T>() : d(0) {}
    };
}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H

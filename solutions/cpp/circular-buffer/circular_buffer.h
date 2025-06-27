#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H
#include <stdexcept>

namespace circular_buffer {

	template <typename T>
	struct circular_buffer {
		using type = T;
		size_t oldest = 0, size = 0, capacity = 0;
		T *data = nullptr;

		void clear() { delete[] data; data = new T[capacity]; oldest = 0; size = 0; }
		
		void overwrite(T val) {
			if (size < capacity) write(val);
			else {
				data[oldest] = val;
				oldest = (oldest + 1) % capacity;
			}
		}

		void write(T val) {
			if (size == capacity) throw std::domain_error("Buffer is full, can't write");

			data[(oldest + size) % capacity] = val;
			size++;
		}
		
		T read() {
			if (size == 0) throw std::domain_error("Buffer size is 0, can't read");
			
			T to_return = data[oldest];

			data[oldest] = T();
			size--;
			oldest = (oldest + 1) % capacity;

			return to_return;
		}

		circular_buffer(size_t _cap) {
			capacity = _cap;
			data = new T[capacity];
		}
		
		~circular_buffer() { delete[] data; }
	};

}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H
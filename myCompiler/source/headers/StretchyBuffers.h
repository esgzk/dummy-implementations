#ifndef STRECHY_BUFFERS_H
#define STRECHY_BUFFERS_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
void* buffer__grow(const void*, size_t, size_t);
typedef struct BufferHeader {
	size_t capacity;
	size_t length;
	char strange_field[0]; //placeholder for array, it's C - quirk or trick
} BufferHeader;


#define __MAX(a, b) ((a) >= (b) ? (a) : (b))
#define buffer__header(buffer_pointer) ((BufferHeader *)((char *)(buffer_pointer) - offsetof(BufferHeader, strange_field))) // return address begin of struct
#define buffer__fits(buffer_pointer, number) (buffer_size(buffer_pointer) + (number) <= buffer_capacity(buffer_pointer))
#define buffer__fit(buffer_pointer, number) ( (buffer__fits(buffer_pointer, number)) ? 0 : ((buffer_pointer) =  buffer__grow(buffer_pointer, buffer_size(buffer_pointer) + (number), sizeof(*(buffer_pointer)))))


#define buffer_capacity(buffer_pointer) ( (buffer_pointer) ? buffer__header(buffer_pointer)->capacity  : 0) // access to capacity through address begin of struct
#define buffer_size(buffer_pointer) ( (buffer_pointer) ? buffer__header(buffer_pointer)->length  : 0) // access to length through address begin of struct
#define buffer_push(buffer_pointer, x) (buffer__fit(buffer_pointer, 1), (buffer_pointer)[buffer__header(buffer_pointer)->length++] = (x))
#define buffer_free(buffer_pointer) ((buffer_pointer) ? free(buffer_pointer) : 0)

void * buffer__grow(const void* buffer, size_t new_length, size_t element_size)
{
	size_t new_capacity = __MAX(1 + 2 * buffer_capacity(buffer), new_length);
	assert(new_capacity >= new_length);
	size_t new_size = new_capacity * element_size;
	BufferHeader* new__header;
	if (buffer)
	{
		new__header = (BufferHeader*)realloc(buffer__header(buffer), new_size);
	}
	else
	{
		new__header = (BufferHeader*)malloc(new_size);
		new__header->length = 0;
	}
	new__header->capacity = new_capacity;
	return new__header->strange_field;
}

#endif






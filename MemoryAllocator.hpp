
#ifndef MemoryAllocator_hpp
	#define MemoryAllocator_hpp

	#include "MemorySize.hpp"

	namespace pankey{

		namespace HolderSystem{

			class MemoryAllocator{
				public:
					virtual ~MemoryAllocator(){}

					virtual void* create(memory_size a_size){return malloc(a_size);}
					virtual void* create(){return nullptr;}
					virtual void destroy(memory_size a_size, void* a_destroy){free(a_destroy);}
					virtual void destroy(void* a_destroy){free(a_destroy);}

					virtual bool isManaged(){
						return this->m_managed;
					}

				protected:
					bool m_managed = false;
			};

		}

	}

#endif
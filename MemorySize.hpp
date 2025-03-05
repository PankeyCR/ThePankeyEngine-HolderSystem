
#ifndef MemorySize_hpp
	#define MemorySize_hpp

	namespace pankey{

		namespace HolderSystem{

			// #if defined(pankey_Windows)
			// 	//#include <iostream>
			// 	//using pointer_size = size_t;
			// 	using pointer_size = decltype(alignof(char));
			// #elif defined(pankey_ArduinoIDE)
			// 	using pointer_size = size_t;
			// #endif

			#ifndef MemorySize(TYPE)

			using memory_size = long;

			template<class P>
			memory_size sizeOfMemory(const P* a_pointer){
				return (char *)(a_pointer + 1) - (char *)(a_pointer);
			}

			template<class P>
			memory_size sizeOfMemory(){
				P i_pointer;
				return sizeOfMemory<P>(&i_pointer);
			}

			#define MemorySize(TYPE) sizeOfMemory<TYPE>()

			#endif
		}
	}

#endif
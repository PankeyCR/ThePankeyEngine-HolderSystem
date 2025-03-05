
#ifndef TableStorage_hpp
	#define TableStorage_hpp

	#include "MemoryHolder.hpp"
	#include "ArrayRawList.hpp"

	#if defined(pankey_Log) && (defined(TableStorage_Log) || defined(pankey_Global_Log) || defined(pankey_HolderSystem_Log))
		#include "Logger_status.hpp"
		#define TableStorageLog(status,method,mns) pankey_Log(status,"TableStorage",method,mns)
	#else
		#define TableStorageLog(status,method,mns)
	#endif

	namespace pankey{

		namespace HolderSystem{

			template<class H>
			class TableStorage{
				public:

					using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
					using VOID_TYPE = typename MemoryHolder<H>::VOID_TYPE;
					using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;

					virtual ~TableStorage(){
						TableStorageLog(pankey_Log_StartMethod, "Destructor", "");
						TableStorageLog(pankey_Log_EndMethod, "Destructor", "");
					}
					
					virtual void setManager(MANAGER_TYPE a_Manager)=0;
					virtual MANAGER_TYPE getManager()const=0;
					
					virtual bool isNull()const=0;
					
					virtual bool isNull(int a_index)const=0;
					virtual bool isKeyNull(int a_index)const=0;
					virtual bool isValueNull(int a_index)const=0;
					
					virtual int getArraySize() const {return this->m_size;}
					virtual int getCollisionSize(int a_index) const {return this->m_size;}
					
					virtual int getSize() const {return this->m_size;}
					
					virtual bool set(int a_position, const MemoryHolder<H>& a_key, const MemoryHolder<H>& a_value)=0;
					
					virtual bool add(int a_position, const MemoryHolder<H>& a_key, const MemoryHolder<H>& a_value)=0;

					virtual bool contain(const MemoryHolder<H>& a_key)const=0;
					
					virtual int getIndex(const MemoryHolder<H>& a_key)const=0;
					
					virtual VOID_TYPE getKeyRawPointer(int a_position)const=0;
					virtual VOID_TYPE getValueRawPointer(int a_position)const=0;
					
					virtual HOLDER_TYPE getKeyHolder(int a_position)const=0;
					virtual HOLDER_TYPE getValueHolder(int a_position)const=0;

					virtual bool removeByPointer(const MemoryHolder<H>& a_key)=0;

					virtual bool removeFirstIndex(int a_length, int a_amount)=0;

					virtual bool removeLastIndex(int a_length, int a_amount)=0;

					virtual bool removePart(int a_index, int a_length, int a_amount)=0;

					virtual bool removeFirst()=0;

					virtual bool removeLast()=0;

					virtual bool clear()=0;

					virtual int reorder()=0;

					virtual int reorder(int a_index, int a_length, int a_amount)=0;

					virtual int reorder(int a_index, int a_length)=0;

					//inserts space on the array, moves the variables from the index to the size specified
					virtual int insert(int a_index, int a_length, int a_size)=0;//return a_index + a_size - 1

					virtual bool expand(int a_adding_size)=0;
					
					virtual bool shrink(int a_amount)=0;
					
					virtual bool destroy()=0;
					
					virtual int getCollisionSize(int a_index){
						if(this->m_collision_size.isEmpty()){
							return -1;
						}
						return this->m_collision_size[a_index];
					}
					
					template<class IM>
					void forEach(IM a_iteration_method){
						TableStorageLog(pankey_Log_StartMethod, "forEach", "");
						if(this->isNull() || this->getSize() <= 0){
							TableStorageLog(pankey_Log_EndMethod, "forEach", "this->isNull() || this->getSize() <= 0");
							return;
						}
						for(int x = 0; x < this->getSize(); x++){
							VOID_TYPE f_key_pointer = this->getKeyRawPointer(x);
							VOID_TYPE f_value_pointer = this->getValueRawPointer(x);
							a_iteration_method(x, this->getSize(), f_key_pointer, f_value_pointer);
						}
						TableStorageLog(pankey_Log_EndMethod, "forEach", "");
					}
					
					template<class IM>
					void forEachNotNull(IM a_iteration_method){
						TableStorageLog(pankey_Log_StartMethod, "forEachNotNull", "");
						if(this->isNull() || this->getSize() <= 0){
							TableStorageLog(pankey_Log_EndMethod, "forEachNotNull", "this->isNull() || this->getSize() <= 0");
							return;
						}
						for(int x = 0; x < this->getSize(); x++){
							VOID_TYPE f_key_pointer = this->getKeyRawPointer(x);
							VOID_TYPE f_value_pointer = this->getValueRawPointer(x);
							if(f_key_pointer == nullptr || f_value_pointer == nullptr){
								TableStorageLog(pankey_Log_Statement, "forEachNotNull", "f_pointer == nullptr");
								continue;
							}
							a_iteration_method(x, this->getSize(), f_key_pointer, f_value_pointer);
						}
						TableStorageLog(pankey_Log_EndMethod, "forEachNotNull", "");
					}
					
				protected:
					Base::ArrayRawList<int> m_collision_size;
					int m_array_size = 0;
					int m_size = 0;
			};

		}

	}

#endif
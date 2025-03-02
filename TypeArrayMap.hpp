
#ifndef TypeArrayMap_hpp
	#define TypeArrayMap_hpp
	
	#include "ValueArrayMapCollection.hpp"
	#include "DuoTypeMember.hpp"
	#include "Pointer.hpp"
	#include "ClassCount.hpp"

	#if defined(pankey_Log) && (defined(TypeArrayMap_Log) || defined(pankey_Global_Log) || defined(pankey_MemoryManager_Log))
		#include "Logger_status.hpp"
		#define TypeArrayMapLog(status,method,mns) pankey_Log(status,"TypeArrayMap",method,mns)
	#else
		#define TypeArrayMapLog(status,method,mns) 
	#endif

	namespace pankey{

		template<class K, class V, class H, class M>
		class TypeArrayMap : public ValueArrayMapCollection<K,V,H,M>{
			public:
				TypeArrayMap(){
					TypeArrayMapLog(pankey_Log_StartMethod, "Constructor", "");
					TypeArrayMapLog(pankey_Log_EndMethod, "Constructor", "");
				}
		
				TypeArrayMap(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "const TypeArrayMap<K,V,H,M>&");
					for(int x = 0; x < a_map.length(); x++){
						Pointer<K,H,M> f_key = a_map.getKey(x);
						Pointer<V,H,M> f_value = a_map.getValue(x);
						this->add(f_key, f_value);
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "");
				}

				virtual ~TypeArrayMap(){
					TypeArrayMapLog(pankey_Log_StartMethod, "Destructor", "");
					TypeArrayMapLog(pankey_Log_EndMethod, "Destructor", "");
				}

				virtual long getKeyType()const{
                    TypeArrayMapLog(pankey_Log_StartMethod, "getKeyType", "");
                    TypeArrayMapLog(pankey_Log_Statement, "getKeyType", ClassCount<K>::get());
                    TypeArrayMapLog(pankey_Log_EndMethod, "getKeyType", "");
					return ClassCount<K>::get();
				}

				virtual long getValueType()const{
                    TypeArrayMapLog(pankey_Log_StartMethod, "getValueType", "");
                    TypeArrayMapLog(pankey_Log_Statement, "getValueType", ClassCount<V>::get());
                    TypeArrayMapLog(pankey_Log_EndMethod, "getValueType", "");
					return ClassCount<V>::get();
				}

				virtual DuoTypeMember<K,V,H,M> add(Pointer<K,H,M> a_key, Pointer<V,H,M> a_value){
					TypeArrayMapLog(pankey_Log_StartMethod, "add", "");
					if(this->m_keys.add(this->m_length, a_key) && this->m_values.add(this->m_length, a_value)){
						TypeArrayMapLog(pankey_Log_Statement, "add", "adding type members");
						this->incrementPosition();
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "add", "");
					return DuoTypeMember<K,V,H,M>(a_key, a_value);
				}

				virtual DuoTypeMember<K,V,H,M> add(Value<K,H,M> a_key, Value<V,H,M> a_value){
					TypeArrayMapLog(pankey_Log_StartMethod, "add", "");
					if(this->m_keys.add(this->m_length, a_key) && this->m_values.add(this->m_length, a_value)){
						TypeArrayMapLog(pankey_Log_Statement, "add", "adding type members");
						this->incrementPosition();
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "add", "");
					return DuoTypeMember<K,V,H,M>(a_key, a_value);
				}

				virtual DuoTypeMember<K,V,H,M> add(DuoTypeMember<K,V,H,M> a_duo){
					TypeArrayMapLog(pankey_Log_StartMethod, "add", "");
					Pointer<K,H,M> i_member = a_duo.getMember();
					Pointer<V,H,M> i_duo_member = a_duo.getDuoTypeMember();
					TypeArrayMapLog(pankey_Log_EndMethod, "add", "");
					return this->add(i_member, i_duo_member);
				}
				
				virtual DuoTypeMember<K,V,H,M> put(DuoTypeMember<K,V,H,M> a_duo){
					TypeArrayMapLog(pankey_Log_StartMethod, "put", "");
					if(this->m_keys.containByPointer(a_duo.getMember())){
						return a_duo;
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "put", "");
					return this->add(a_duo);
				}
				
				virtual DuoTypeMember<K,V,H,M> put(Pointer<K,H,M> a_key, Pointer<V,H,M> a_value){
					TypeArrayMapLog(pankey_Log_StartMethod, "put", "");
					if(this->m_keys.containByPointer(a_key)){
						return DuoTypeMember<K,V,H,M>(a_key, a_value);
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "put", "");
					return this->add(a_key, a_value);
				}
				
				virtual DuoTypeMember<K,V,H,M> put(Value<K,H,M> a_key, Value<V,H,M> a_value){
					TypeArrayMapLog(pankey_Log_StartMethod, "put", "");
					if(this->m_keys.containByPointer(a_key)){
						return DuoTypeMember<K,V,H,M>(a_key, a_value);
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "put", "");
					return this->add(a_key, a_value);
				}
		
				virtual TypeArrayMap<K,V,H,M>& operator=(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "const TypeArrayMap<K,V,H,M>&");
					for(int x = 0; x < a_map.length(); x++){
						Pointer<K,H,M> f_key = a_map.getKey(x);
						Pointer<V,H,M> f_value = a_map.getValue(x);
						this->add(f_key, f_value);
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "");
					return *this;
				}
		
				virtual bool operator==(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "const TypeArrayMap<K,V,H,M>&");
					if(this->length() != a_map.length()){
						return false;
					}
					for(int x = 0; x < a_map.length(); x++){
						auto f_key_1 = this->getKey(x);
						auto f_value_1 = this->getValue(x);
						auto f_key_2 = a_map.getKey(x);
						auto f_value_2 = a_map.getValue(x);
						if(f_key_1 != f_key_2 || f_value_1 != f_value_2){
							return false;
						}
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "");
					return true;
				}
		
				virtual bool operator!=(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "const TypeArrayMap<K,V,H,M>&");
					if(this->length() != a_map.length()){
						return true;
					}
					for(int x = 0; x < a_map.length(); x++){
						auto f_key_1 = this->getKey(x);
						auto f_value_1 = this->getValue(x);
						auto f_key_2 = a_map.getKey(x);
						auto f_value_2 = a_map.getValue(x);
						if(f_key_1 != f_key_2 || f_value_1 != f_value_2){
							return true;
						}
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "");
					return false;
				}
		};

	}

#endif
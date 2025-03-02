
#ifndef MemoryHolder_hpp
	#define MemoryHolder_hpp

    #include "MemoryManager.hpp"
	#include "MemoryHolderManager.hpp"

	#if defined(pankey_Log) && (defined(MemoryHolder_Log) || defined(pankey_Global_Log) || defined(pankey_MemoryManager_Log))
		#include "Logger_status.hpp"
        #define MemoryHolderLog(status,method,mns) pankey_Log(status,"MemoryHolder",method,mns)
    #else
        #define MemoryHolderLog(status,method,mns)
    #endif

	namespace pankey{

        template<class H>
        class MemoryHolder{
            public:
				using HOLDER_TYPE = H*;

                using MANAGER_TYPE = MemoryManager<H>*;
                using VOID_TYPE = void*;
                
                virtual ~MemoryHolder(){
                    MemoryHolderLog(pankey_Log_StartMethod, "Destructor", "");
                    MemoryHolderLog(pankey_Log_EndMethod, "Destructor", "");
                }

                virtual void remove(){
                    MemoryHolderLog(pankey_Log_StartMethod, "remove", "");
                    MemoryHolderManager<H>::remove(this->getManager(), m_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "remove", "");
                }

                virtual void destroy(){
                    MemoryHolderLog(pankey_Log_StartMethod, "destroy", "");
                    MemoryHolderManager<H>::destroy(this->getManager(), m_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "destroy", "");
                }
                    
                //unsafe method
                virtual void setHolder(HOLDER_TYPE a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "setHolder", "");
					MemoryHolderManager<H>::add(this->getManager(), a_holder);
					MemoryHolderManager<H>::remove(this->getManager(), m_holder);
					m_holder = a_holder;
                    MemoryHolderLog(pankey_Log_EndMethod, "setHolder", "");
                }

                //unsafe method
                virtual HOLDER_TYPE getHolder()const{
                    return m_holder;
                }

                virtual HOLDER_TYPE& getHolderReference(){
                    return m_holder;
                }

                virtual bool isHolderNull()const{
                    return m_holder == nullptr;
                }
                    
                virtual void setManager(MANAGER_TYPE a_llocator){
                    MemoryHolderLog(pankey_Log_StartMethod, "setManager", "");
                    MemoryHolderLog(pankey_Log_EndMethod, "setManager", "");
                }

                virtual MANAGER_TYPE getManager()const=0;

                virtual bool isManagerNull()const{
                    return this->getManager() == nullptr;
                }

                virtual void copyMemoryHolder(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "copyMemoryHolder", "");
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(pankey_Log_EndMethod, "copyMemoryHolder", "");
                }

				virtual bool shareManager(MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "shareManager", "");
                    if(a_manager == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "The variable cheching has no Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "");
                        return false;
                    }
                    auto i_manager = this->getManager();
                    if(i_manager == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "MemoryHolder doesnt have Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "shareManager", a_manager == i_manager);
                    return a_manager == i_manager;
				}

				virtual bool shareManager(const MemoryHolder<H>& a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "shareManager", "");
                    auto i_manager_in = a_holder.getManager();
                    if(i_manager_in == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "The variable cheching has no Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "");
                        return false;
                    }
                    auto i_manager = this->getManager();
                    if(i_manager == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "MemoryHolder doesnt have Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "shareManager", i_manager_in == i_manager);
                    return i_manager_in == i_manager;
				}

				virtual bool sameType(long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "sameType", "");
                    MemoryHolderLog(pankey_Log_Statement, "sameType", "a_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameType", a_type);
                    if(a_type == -1){
                        MemoryHolderLog(pankey_Log_Error, "sameType", "The variable cheching has no type");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameType", "");
                        return false;
                    }
                    long i_type = this->getType();
                    MemoryHolderLog(pankey_Log_Statement, "sameType", "i_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameType", i_type);
                    if(i_type == -1){
                        MemoryHolderLog(pankey_Log_EndMethod, "sameType", "");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "sameType", i_type == a_type);
                    return i_type == a_type;
				}

				virtual bool sameBaseType(long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "sameBaseType", "");
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", "a_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", a_type);
                    if(a_type == -1){
                        MemoryHolderLog(pankey_Log_Error, "sameBaseType", "The variable cheching has no type");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "");
                        return false;
                    }
                    long i_type = this->getBaseType();
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", "i_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", i_type);
                    if(i_type == -1){
                        MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", i_type == a_type);
                    return i_type == a_type;
				}

				virtual bool isMember(MANAGER_TYPE a_manager, long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "MANAGER_TYPE a_manager, long a_type");
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "");
                    return (this->sameType(a_type) || this->sameBaseType(a_type)) && this->shareManager(a_manager);
				}

				virtual bool isMember(HOLDER_TYPE a_holder, MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "HOLDER_TYPE a_holder, MANAGER_TYPE a_manage");
                    auto i_type = MemoryHolderManager<H>::getType(a_manager, a_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "");
                    return this->isMember(a_manager, i_type);
                }

				virtual bool isMember(HOLDER_TYPE a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "HOLDER_TYPE a_holder");
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "");
                    return this->isMember(a_holder, this->getManager());
                }

				virtual bool isMember(const MemoryHolder<H>& a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "const MemoryHolder<H>& a_holder");
                    auto i_manager = a_holder.getManager();
                    auto i_type = a_holder.getType();
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "");
                    return this->isMember(i_manager, i_type);
                }

				virtual void setType(long a_type){
                    MemoryHolderLog(pankey_Log_StartMethod, "setType", "");
					MemoryHolderManager<H>::setType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(pankey_Log_EndMethod, "setType", "");
				}

				virtual long getType()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getType", "");
                    MemoryHolderLog(pankey_Log_EndMethod, "getType", "");
					return MemoryHolderManager<H>::getType(this->getManager(), this->m_holder);
				}

				virtual void setBaseType(long a_type){
                    MemoryHolderLog(pankey_Log_StartMethod, "setBaseType", "");
					MemoryHolderManager<H>::setBaseType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(pankey_Log_EndMethod, "setBaseType", "");
				}

				virtual long getBaseType()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getBaseType", "");
                    MemoryHolderLog(pankey_Log_EndMethod, "getBaseType", "");
					return MemoryHolderManager<H>::getBaseType(this->getManager(), this->m_holder);
				}

				virtual bool isMemoryNull()const{
					MemoryHolderLog(pankey_Log_StartMethod, "isMemoryNull", "");
					if(m_holder == nullptr){
						MemoryHolderLog(pankey_Log_EndMethod, "isMemoryNull", "m_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "isMemoryNull",  "isNull: ");
					MemoryHolderLog(pankey_Log_Statement, "isMemoryNull",  i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "isMemoryNull", "");
					return i_pointer == nullptr;
				}

				virtual bool isNull()const{
					MemoryHolderLog(pankey_Log_StartMethod, "isNull", "");
					if(m_holder == nullptr){
						MemoryHolderLog(pankey_Log_EndMethod, "isNull", "m_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "isNull",  "isNull: ");
					MemoryHolderLog(pankey_Log_Statement, "isNull",  i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "isNull", "");
					return i_pointer == nullptr;
				}

				//unsafe method
				virtual VOID_TYPE getRawPointer()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getRawPointer", "");
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "getRawPointer", "VOID_TYPE is null?");
					MemoryHolderLog(pankey_Log_Statement, "getRawPointer",  i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "getRawPointer", "");
					return i_pointer;
				}

                virtual void operator=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator=", "");
                    if(!this->shareManager(a_holder)){
                        MemoryHolderLog(pankey_Log_Error, "operator=",  "MemoryHolder is not Member of Variable");
                        MemoryHolderLog(pankey_Log_EndMethod, "operator=", "");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(pankey_Log_EndMethod, "operator=", "");
                }

                virtual bool operator==(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator==", "");
                    MemoryHolderLog(pankey_Log_EndMethod, "operator==",  this->getHolder() == a_holder.getHolder());
                    return this->getHolder() == a_holder.getHolder();
                }

                virtual bool operator!=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator!=", "");
                    MemoryHolderLog(pankey_Log_EndMethod, "operator!=",  this->getHolder() != a_holder.getHolder());
                    return this->getHolder() != a_holder.getHolder();
                }

            protected:

                HOLDER_TYPE m_holder = nullptr;
            
        };

	}

#endif
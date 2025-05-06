
namespace pankey{
  template<class T>
  String toString(const T& a_add){
    return String(a_add);
  }

  template<class T>
  String concat(const T& a_add){
    return String(a_add);
  }

  template<class T, class... Args>
  String concat(const T& a_string, const Args&... a_add){
    String i_string = String(a_string) + concat(a_add...);
    return i_string;
  }
}

#include "TestRunner.hpp"

#include "TR_DuoMember_Testing.hpp"
#include "TR_DuoTypeMember_Testing.hpp"
#include "TR_InvokeCommandList_Testing.hpp"
#include "TR_InvokeCommandMap_Testing.hpp"
#include "TR_InvokeList_Testing.hpp"
#include "TR_MemberArrayMap_Testing.hpp"
#include "TR_MemberArrayStorage_Testing.hpp"
#include "TR_MemberList_Testing.hpp"
#include "TR_Object_Testing.hpp"
#include "TR_ObjectArrayMap_Testing.hpp"
#include "TR_ObjectList_Testing.hpp"
#include "TR_Pointer_Testing.hpp"
#include "TR_TypeArrayMap_Testing.hpp"
#include "TR_TypeList_Testing.hpp"
#include "TR_Value_Testing.hpp"
#include "TR_Variable_Testing.hpp"

using namespace pankey::Base;
using namespace pankey::HolderSystem;

void Start(){
  Serial.println("Start Test");
}

void End(){
  Serial.println("End Test");
}

void Info(const String& a_test, const String& a_info){
  Serial.print("Test: ");Serial.println(a_test);
  Serial.println(a_info);
}

void Error(const String& a_test, const String& a_error){
  Serial.print("Test: ");Serial.println(a_test);
  Serial.println(a_error);
}

void Succes(){
  Serial.println("Test Complete with no errors");
}

TestRunner<String> tester;

void setup() {
  Serial.begin(9600);
  
  TR_DuoMember_Testing(tester);
  TR_DuoTypeMember_Testing(tester);
  TR_InvokeCommandList_Testing(tester);
  TR_InvokeCommandMap_Testing(tester);
  TR_InvokeList_Testing(tester);
  TR_MemberArrayMap_Testing(tester);
  TR_MemberArrayStorage_Testing(tester);
  TR_MemberList_Testing(tester);
  TR_Object_Testing(tester);
  TR_ObjectArrayMap_Testing(tester);
  TR_ObjectList_Testing(tester);
  TR_Pointer_Testing(tester);
  TR_TypeArrayMap_Testing(tester);
  TR_TypeList_Testing(tester);
  TR_Value_Testing(tester);
  TR_Variable_Testing(tester);
  
  tester.output(Start, End, Info, Error, Succes);
}

void loop() {
  tester.runTest();
  tester.run();
  // Serial.println(ESP.getFreeHeap());
  delay(3000);
}
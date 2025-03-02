
//#include "arduino_logger.hpp"

//#define TestRunner_Log

#include "TestRunner.hpp"

#include "TR_DuoMember_Testing.hpp"
#include "TR_DuoTypeMember_Testing.hpp"
#include "TR_Function_Testing.hpp"
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

using namespace pankey;

void Start(){
  Serial.println("Start Test");
}

void End(){
  Serial.println("End Test");
}

void Info(const CharArray& a_test, const CharArray& a_info){
  Serial.print("Test: ");Serial.println(a_test.pointer());
  Serial.println(a_info.pointer());
}

void Error(const CharArray& a_test, const CharArray& a_error){
  Serial.print("Test: ");Serial.println(a_test.pointer());
  Serial.println(a_error.pointer());
}

void Succes(){
  Serial.println("Test Complete with no errors");
}

TestRunner tester;

void setup() {
  Serial.begin(9600);
  
//  pankey_Log_set(Log);

  TR_DuoMember_Testing(tester);
  TR_DuoTypeMember_Testing(tester);
  TR_Function_Testing(tester);
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
  delay(3000);
}
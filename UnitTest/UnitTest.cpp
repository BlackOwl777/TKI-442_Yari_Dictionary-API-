#include "pch.h"
#include "Dictionary.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dictionary; // ������������ ���� ��� ������ Dictionary.

namespace UnitTest {
    TEST_CLASS(DictionaryTest) {
public:

    TEST_METHOD(AddAndGetValue_ValidKeyValue_PairStoredCorrectly) {
        Dictionary dict;
        dict.add("key1", "value1");
        dict.add("key2", "value2");
        Assert::AreEqual(std::string("value1"), dict.get("key1"));
        Assert::AreEqual(std::string("value2"), dict.get("key2"));
    }

    TEST_METHOD(RemoveKey_KeyExists_RemovedSuccessfully) {
        Dictionary dict;
        dict.add("key1", "value1");
        dict.add("key2", "value2");
        dict.remove("key1");
        Assert::ExpectException<std::runtime_error>([&dict]() { dict.get("key1"); },
            L"��������� ���������� ��� ������� �������� ��������� ����.");
    }

    TEST_METHOD(Get_NonexistentKey_ExceptionThrown) {
        Dictionary dict;
        Assert::ExpectException<std::runtime_error>([&dict]() { dict.get("nonexistent"); },
            L"��������� ���������� ��� ��������� �������� �� ��������������� �����.");
    }

    TEST_METHOD(ContainsKey_ExistingAndNonExistingKeys_ReturnsCorrectValues) {
        Dictionary dict;
        dict.add("key1", "value1");
        Assert::IsTrue(dict.containsKey("key1"), L"���� 'key1' ������ ������������ � �������.");
        Assert::IsFalse(dict.containsKey("key2"), L"���� 'key2' �� ������ ������������ � �������.");
    }

    TEST_METHOD(IsEmpty_EmptyAndNonEmptyDictionary_ReturnsCorrectValues) {
        Dictionary dict;
        Assert::IsTrue(dict.isEmpty(), L"������� ������ ���� ������.");
        dict.add("key1", "value1");
        Assert::IsFalse(dict.isEmpty(), L"������� �� ������ ���� ������.");
    }
    };
}

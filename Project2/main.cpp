//#include "WeddingGuest.h"
//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//#include <type_traits>
//
//#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }
//static_assert(std::is_default_constructible<WeddingGuest>::value
//	, "Map must be default-constructible.");
//
//static_assert(std::is_copy_constructible<WeddingGuest>::value,
//	"Map must be copy-constructible.");
//void ThisFunctionWillNeverBeCalled() {
//	CHECKTYPE(&WeddingGuest::operator=, WeddingGuest &
//		(WeddingGuest::*)(const WeddingGuest&));
//	CHECKTYPE(&WeddingGuest::noGuests, bool
//	(WeddingGuest::*)() const);
//	CHECKTYPE(&WeddingGuest::guestCount, int
//	(WeddingGuest::*)() const);
//	CHECKTYPE(&WeddingGuest::inviteGuest, bool (WeddingGuest::*)
//		(const std::string&, const std::string&, const
//			GuestType&));
//	CHECKTYPE(&WeddingGuest::alterGuest, bool
//	(WeddingGuest::*)(const std::string&, const std::string&,
//		const GuestType&));
//	CHECKTYPE(&WeddingGuest::inviteOrAlter, bool
//	(WeddingGuest::*)(const std::string&, const std::string&,
//		const GuestType&));
//	CHECKTYPE(&WeddingGuest::crossGuestOff, bool
//	(WeddingGuest::*)
//		(const std::string&, const std::string&));
//	CHECKTYPE(&WeddingGuest::invitedToTheWedding, bool
//	(WeddingGuest::*)(const std::string&, const std::string&)
//		const);
//	CHECKTYPE(&WeddingGuest::matchInvitedGuest, bool
//	(WeddingGuest::*)
//		(const std::string&, const std::string&, GuestType&)
//		const);
//	CHECKTYPE(&WeddingGuest::verifyGuestOnTheList, bool
//	(WeddingGuest::*)
//		(int, std::string&, std::string&, GuestType&)
//		const);
//	CHECKTYPE(&WeddingGuest::swapWeddingGuests, void
//	(WeddingGuest::*)(WeddingGuest&));
//	CHECKTYPE(joinGuests, bool (*)(const WeddingGuest&, const
//		WeddingGuest&, WeddingGuest&));
//	CHECKTYPE(attestGuests, void (*)(const std::string&,
//		const std::string&, const WeddingGuest&, WeddingGuest&));
//}
//
////void testdouble() {
////
////	//all tets run with GuestType == double
////  // default constructor
////WeddingGuest lal;
////// For an empty list:
////assert(lal.guestCount() == 0); // test size
////assert(lal.noGuests()); // test empty
////assert(!lal.crossGuestOff("Malik", "Monk")); // nothing to erase 
//// 
////	WeddingGuest youngins;
////	assert(youngins.inviteGuest("Lauren", "U", 23));//tests invite guest
////	assert(youngins.inviteGuest("James", "H", 29));
////	assert(youngins.guestCount() == 2);//tests guest count
////	string first, last;
////	double a;
////	assert(youngins.verifyGuestOnTheList(0, first, last, a) && a//tests verifyGuestsOnTheList of first index
////		== 29);
////	assert(youngins.verifyGuestOnTheList(1, first, last, a) &&//tests verifyGuestsOnList of last index
////		(first == "Lauren" && a == 23));
////
////
////	WeddingGuest groomsmen;
////	groomsmen.inviteGuest("Tony", "Ambrosio", 40);
////	groomsmen.inviteGuest("Long", "Le", 41);
////	groomsmen.inviteGuest("Mike", "Wu", 43);
////	groomsmen.inviteGuest("Robert", "Wells", 44);
////	groomsmen.inviteGuest("Justin", "Sandobal", 37);
////	groomsmen.inviteGuest("Nelson", "Villaluz", 38);
////
////	WeddingGuest bridesmaids;
////	bridesmaids.inviteGuest("Serra", "Park", 39.5);
////	bridesmaids.inviteGuest("Saadia", "Parker", 37.5);
////	assert(!bridesmaids.invitedToTheWedding("", ""));//tests invitedToWedding when guest isnt invited
////	bridesmaids.inviteGuest("Patricia", "Kim", 39.0);
////	bridesmaids.inviteGuest("", "", 21.0);
////	bridesmaids.inviteGuest("Kristin", "Livingston", 38.0);
////	assert(bridesmaids.invitedToTheWedding("", ""));//tests invitedtoWedding when guest is invited
////	bridesmaids.crossGuestOff("Patricia", "Kim");
////	assert(bridesmaids.guestCount() == 4
////		&& bridesmaids.invitedToTheWedding("Serra", "Park")//tests invitedToWedding
////		&& bridesmaids.invitedToTheWedding("Saadia", "Parker")
////		&& bridesmaids.invitedToTheWedding("Kristin", "Livingston")
////		&& bridesmaids.invitedToTheWedding("", ""));
////
////	//checks alphabetical order
////	//groomsmen.dump();
////	//bridesmaids.dump();
////
////	//test crossGuestOff
////	groomsmen.crossGuestOff("Robert", "Wells");
////	groomsmen.crossGuestOff("Mike", "Wu");
////	assert(!groomsmen.crossGuestOff("Cynthia", "Nguyen"));
////	assert(groomsmen.guestCount() == 4);
////	
////	//tests cross all guests off
////	WeddingGuest test0;
////	GuestType value;
////	test0.inviteGuest("test", "test", 0);
////	test0.inviteGuest("test1", "test1", 0);
////	test0.inviteGuest("test2", "test2", 0);
////	while(!test0.noGuests())//tests noGuests
////	{
////		test0.verifyGuestOnTheList(0, first, last, value);
////		test0.crossGuestOff(first, last);
////	}
////	assert(test0.noGuests());//tests noGuests
////	//cout << "pass test 0" << endl;
////
////	//tests swapWeddingGuests
////	groomsmen.swapWeddingGuests(bridesmaids);
////	assert(groomsmen.guestCount() == 4
////		&& groomsmen.invitedToTheWedding("Serra", "Park")
////		&& groomsmen.invitedToTheWedding("Saadia", "Parker")
////		&& groomsmen.invitedToTheWedding("Kristin", "Livingston")
////		&& groomsmen.invitedToTheWedding("", ""));
////
////	//groomsmen.dump();
////	//bridesmaids.dump();
////
////	bridesmaids.swapWeddingGuests(groomsmen);
////	assert(bridesmaids.guestCount() == 4
////		&& bridesmaids.invitedToTheWedding("Serra", "Park")
////		&& bridesmaids.invitedToTheWedding("Saadia", "Parker")
////		&& bridesmaids.invitedToTheWedding("Kristin", "Livingston")
////		&& bridesmaids.invitedToTheWedding("", ""));
////
////	//tests copy constructor, assignment operator
////	string first1;
////	string last1;
////	GuestType value1;
////	WeddingGuest temp = groomsmen;//cpy constructor
////	assert(groomsmen.verifyGuestOnTheList(0, first, last, value) == temp.verifyGuestOnTheList(0, first1, last1, value1) && groomsmen.guestCount() == temp.guestCount());
////	groomsmen = bridesmaids;//assignment operator
////	assert(groomsmen.verifyGuestOnTheList(0, first, last, value) == bridesmaids.verifyGuestOnTheList(0, first1, last1, value1) && groomsmen.guestCount() == bridesmaids.guestCount());
////	groomsmen = temp;
////	cout << "pass constructor and assignment operator" << endl;
////
////	bridesmaids.inviteGuest("Tony", "Ambrosio", 0);
////
////	//tests matchInvitedGuest && alterGuest
////	assert(bridesmaids.alterGuest("Tony", "Ambrosio", 43) && bridesmaids.matchInvitedGuest("Tony", "Ambrosio", value) && value == 43);
////	assert(!bridesmaids.alterGuest("Cynthia", "Nguyen", 20));
////
////	//test inviteOrAlter
////	assert(bridesmaids.inviteOrAlter("Cynthia", "Nguyen", 19) && bridesmaids.guestCount() == 6);
////	assert(bridesmaids.inviteOrAlter("Tony", "Ambrosio", 60) && bridesmaids.matchInvitedGuest("Tony", "Ambrosio", value) && value == 60 && bridesmaids.guestCount() == 6);
////
////	//tests nonmember functions//
////
////	//tests joinGuests
////	WeddingGuest test1;
////	joinGuests(groomsmen, bridesmaids, test1);//odJined is empty
////	joinGuests(groomsmen, bridesmaids, temp);//odJoined containes values
////	assert(test1.verifyGuestOnTheList(0, first, last, value) == temp.verifyGuestOnTheList(0, first1, last1, value1) && test1.guestCount() == temp.guestCount());
////
////	attestGuests("*", "*", test1, temp);//both first and last are wild
////	//temp.dump();
////
////	WeddingGuest test2;
////	WeddingGuest test2_1;
////	test2.inviteGuest("Anthony", "Nguyen", 18);
////	test2.inviteGuest("Cynthia", "Nguyen", 19);
////	test2.inviteGuest("Phuong", "Tran", 76);
////	test2.inviteGuest("Khanh", "Nguyen", 64);
////	test2.inviteGuest("Kelvin", "Thoi", 23);
////	test2.inviteGuest("Cynthia", "Tran", 19);
////
////	attestGuests("*", "Nguyen", test2, temp);//test only first is wild and odResult is not empty
////	attestGuests("*", "Nguyen", test2, test2_1);//test only first is wild and odResult is empty
////	//temp.dump()
////	//test2_1.dump()
////	assert(temp.guestCount() == test2_1.guestCount());
////	assert(test2_1.guestCount() == 3);
////
////	attestGuests("Cynthia", "*", test2, temp);//test only last is wild
////	assert(temp.guestCount() == 2);
////
////	attestGuests("Cynthia", "*", test2, test2);//tests if both odOne and odResults are same linked list
////	assert(test2.guestCount() == 2 && test2.invitedToTheWedding("Cynthia", "Nguyen") && test2.invitedToTheWedding("Cynthia", "Tran"));
////
////	return;
////}
////void testint() {
////
////	//all tets run with GuestType == int
//// // default constructor
////WeddingGuest lal;
////// For an empty list:
////assert(lal.guestCount() == 0); // test size
////assert(lal.noGuests()); // test empty
////assert(!lal.crossGuestOff("Malik", "Monk")); // nothing to erase 
////	WeddingGuest youngins;
////	assert(youngins.inviteGuest("Lauren", "U", 23));//tests invite guest
////	assert(youngins.inviteGuest("James", "H", 29));
////	assert(youngins.guestCount() == 2);//tests guest count
////	string first, last;
////	int a;
////	assert(youngins.verifyGuestOnTheList(0, first, last, a) && a//tests verifyGuestsOnTheList of first index
////		== 29);
////	assert(youngins.verifyGuestOnTheList(1, first, last, a) &&//tests verifyGuestsOnList of last index
////		(first == "Lauren" && a == 23));
////
////
////	WeddingGuest groomsmen;
////	groomsmen.inviteGuest("Tony", "Ambrosio", 40);
////	groomsmen.inviteGuest("Long", "Le", 41);
////	groomsmen.inviteGuest("Mike", "Wu", 43);
////	groomsmen.inviteGuest("Robert", "Wells", 44);
////	groomsmen.inviteGuest("Justin", "Sandobal", 37);
////	groomsmen.inviteGuest("Nelson", "Villaluz", 38);
////
////	WeddingGuest bridesmaids;
////	bridesmaids.inviteGuest("Serra", "Park", 39);
////	bridesmaids.inviteGuest("Saadia", "Parker", 37);
////	assert(!bridesmaids.invitedToTheWedding("", ""));//tests invitedToWedding when guest isnt invited
////	bridesmaids.inviteGuest("Patricia", "Kim", 39);
////	bridesmaids.inviteGuest("", "", 21);
////	bridesmaids.inviteGuest("Kristin", "Livingston", 38);
////	assert(bridesmaids.invitedToTheWedding("", ""));//tests invitedtoWedding when guest is invited
////	bridesmaids.crossGuestOff("Patricia", "Kim");
////	assert(bridesmaids.guestCount() == 4
////		&& bridesmaids.invitedToTheWedding("Serra", "Park")//tests invitedToWedding
////		&& bridesmaids.invitedToTheWedding("Saadia", "Parker")
////		&& bridesmaids.invitedToTheWedding("Kristin", "Livingston")
////		&& bridesmaids.invitedToTheWedding("", ""));
////
////	//checks alphabetical order
////	//groomsmen.dump();
////	//bridesmaids.dump();
////
////	//test crossGuestOff
////	groomsmen.crossGuestOff("Robert", "Wells");
////	groomsmen.crossGuestOff("Mike", "Wu");
////	assert(!groomsmen.crossGuestOff("Cynthia", "Nguyen"));
////	assert(groomsmen.guestCount() == 4);
////
////	//tests cross all guests off
////	WeddingGuest test0;
////	GuestType value;
////	test0.inviteGuest("test", "test", 0);
////	test0.inviteGuest("test1", "test1", 0);
////	test0.inviteGuest("test2", "test2", 0);
////	while (!test0.noGuests())//tests noGuests
////	{
////		test0.verifyGuestOnTheList(0, first, last, value);
////		test0.crossGuestOff(first, last);
////	}
////	assert(test0.noGuests());//tests noGuests
////	//cerr << "pass test 0" << endl;
////
////	//tests swapWeddingGuests
////	groomsmen.swapWeddingGuests(bridesmaids);
////	assert(groomsmen.guestCount() == 4
////		&& groomsmen.invitedToTheWedding("Serra", "Park")
////		&& groomsmen.invitedToTheWedding("Saadia", "Parker")
////		&& groomsmen.invitedToTheWedding("Kristin", "Livingston")
////		&& groomsmen.invitedToTheWedding("", ""));
////
////	//groomsmen.dump();
////	//bridesmaids.dump();
////
////	bridesmaids.swapWeddingGuests(groomsmen);
////	assert(bridesmaids.guestCount() == 4
////		&& bridesmaids.invitedToTheWedding("Serra", "Park")
////		&& bridesmaids.invitedToTheWedding("Saadia", "Parker")
////		&& bridesmaids.invitedToTheWedding("Kristin", "Livingston")
////		&& bridesmaids.invitedToTheWedding("", ""));
////
////	//groomsmen.dump();
////	//bridesmaids.dump();
////	//cerr << "pass swap test" << endl;
////
////	//tests copy constructor, assignment operator
////	string first1;
////	string last1;
////	GuestType value1;
////	WeddingGuest temp = groomsmen;//cpy constructor
////	assert(groomsmen.verifyGuestOnTheList(0, first, last, value) == temp.verifyGuestOnTheList(0, first1, last1, value1) && groomsmen.guestCount() == temp.guestCount());
////	groomsmen = bridesmaids;//assignment operator
////	assert(groomsmen.verifyGuestOnTheList(0, first, last, value) == bridesmaids.verifyGuestOnTheList(0, first1, last1, value1) && groomsmen.guestCount() == bridesmaids.guestCount());
////	groomsmen = temp;
////	//cerr << "pass constructor and assignment operator" << endl;
////
////	bridesmaids.inviteGuest("Tony", "Ambrosio", 0);
////
////	//tests matchInvitedGuest && alterGuest
////	assert(bridesmaids.alterGuest("Tony", "Ambrosio", 43) && bridesmaids.matchInvitedGuest("Tony", "Ambrosio", value) && value == 43);
////	assert(!bridesmaids.alterGuest("Cynthia", "Nguyen", 20));
////
////	//test inviteOrAlter
////	assert(bridesmaids.inviteOrAlter("Cynthia", "Nguyen", 19) && bridesmaids.guestCount() == 6);
////	assert(bridesmaids.inviteOrAlter("Tony", "Ambrosio", 60) && bridesmaids.matchInvitedGuest("Tony", "Ambrosio", value) && value == 60 && bridesmaids.guestCount() == 6);
////
////	//tests nonmember functions//
////
////	//tests joinGuests
////	WeddingGuest test1;
////	joinGuests(groomsmen, bridesmaids, test1);//odJined is empty
////	joinGuests(groomsmen, bridesmaids, temp);//odJoined containes values
////	assert(test1.verifyGuestOnTheList(0, first, last, value) == temp.verifyGuestOnTheList(0, first1, last1, value1) && test1.guestCount() == temp.guestCount());
////
////	attestGuests("*", "*", test1, temp);//both first and last are wild
////	//temp.dump();
////
////	WeddingGuest test2;
////	WeddingGuest test2_1;
////	test2.inviteGuest("Anthony", "Nguyen", 18);
////	test2.inviteGuest("Cynthia", "Nguyen", 19);
////	test2.inviteGuest("Phuong", "Tran", 76);
////	test2.inviteGuest("Khanh", "Nguyen", 64);
////	test2.inviteGuest("Kelvin", "Thoi", 23);
////	test2.inviteGuest("Cynthia", "Tran", 19);
////
////	attestGuests("*", "Nguyen", test2, temp);//test only first is wild and odResult is not empty
////	attestGuests("*", "Nguyen", test2, test2_1);//test only first is wild and odResult is empty
////	//temp.dump()
////	//test2_1.dump()
////	assert(temp.guestCount() == test2_1.guestCount());
////	assert(test2_1.guestCount() == 3);
////
////	attestGuests("Cynthia", "*", test2, temp);//test only last is wild
////	assert(temp.guestCount() == 2);
////
////	attestGuests("Cynthia", "*", test2, test2);//tests if both odOne and odResults are same linked list
////	assert(test2.guestCount() == 2 && test2.invitedToTheWedding("Cynthia", "Nguyen") && test2.invitedToTheWedding("Cynthia", "Tran"));
////
////	return;
////}
//
//void teststring() {
//
//	// default constructor
//	WeddingGuest lal;
//	// For an empty list:
//	assert(lal.guestCount() == 0); // test size
//	assert(lal.noGuests()); // test empty
//	assert(!lal.crossGuestOff("Malik", "Monk")); // nothing to erase 
//
//	//all tets run with GuestType == string
//	WeddingGuest youngins;
//	assert(youngins.inviteGuest("Lauren", "U", "23"));//tests invite guest
//	assert(youngins.inviteGuest("James", "H", "29"));
//	assert(youngins.guestCount() == 2);//tests guest count
//	string first, last;
//	string a;
//	assert(youngins.verifyGuestOnTheList(0, first, last, a) && a//tests verifyGuestsOnTheList of first index
//		== "29");
//	assert(youngins.verifyGuestOnTheList(1, first, last, a) &&//tests verifyGuestsOnList of last index
//		(first == "Lauren" && a == "23"));
//
//
//	WeddingGuest groomsmen;
//	groomsmen.inviteGuest("Tony", "Ambrosio", "40");
//	groomsmen.inviteGuest("Long", "Le", "41");
//	groomsmen.inviteGuest("Mike", "Wu", "43");
//	groomsmen.inviteGuest("Robert", "Wells", "44");
//	groomsmen.inviteGuest("Justin", "Sandobal", "37");
//	groomsmen.inviteGuest("Nelson", "Villaluz", "38");
//
//	WeddingGuest bridesmaids;
//	bridesmaids.inviteGuest("Serra", "Park", "39");
//	bridesmaids.inviteGuest("Saadia", "Parker", "37");
//	assert(!bridesmaids.invitedToTheWedding("", ""));//tests invitedToWedding when guest isnt invited
//	bridesmaids.inviteGuest("Patricia", "Kim", "39");
//	bridesmaids.inviteGuest("", "", "21");
//	bridesmaids.inviteGuest("Kristin", "Livingston", "38");
//	assert(bridesmaids.invitedToTheWedding("", ""));//tests invitedtoWedding when guest is invited
//	bridesmaids.crossGuestOff("Patricia", "Kim");
//	assert(bridesmaids.guestCount() == 4
//		&& bridesmaids.invitedToTheWedding("Serra", "Park")//tests invitedToWedding, test all guest invited are on list
//		&& bridesmaids.invitedToTheWedding("Saadia", "Parker")
//		&& bridesmaids.invitedToTheWedding("Kristin", "Livingston")
//		&& bridesmaids.invitedToTheWedding("", ""));
//
//	//checks alphabetical order
//	//groomsmen.dump();
//	//bridesmaids.dump();
//
//	//test crossGuestOff
//	groomsmen.crossGuestOff("Robert", "Wells");
//	groomsmen.crossGuestOff("Mike", "Wu");
//	assert(!groomsmen.crossGuestOff("Cynthia", "Nguyen"));//tests when not on list
//	assert(groomsmen.guestCount() == 4);
//
//	//tests cross all guests off
//	WeddingGuest test0;
//	GuestType value;
//	test0.inviteGuest("test", "test", "0");
//	test0.inviteGuest("test1", "test1", "0");
//	test0.inviteGuest("test2", "test2", "0");
//	while (!test0.noGuests())//tests noGuests
//	{
//		test0.verifyGuestOnTheList(0, first, last, value);
//		test0.crossGuestOff(first, last);
//	}
//	assert(test0.noGuests());//tests noGuests
//	//cerr << "pass test 0" << endl;
//
//	//tests swapWeddingGuests
//	groomsmen.swapWeddingGuests(bridesmaids);
//	assert(groomsmen.guestCount() == 4//test groomsmen containes bridesmaids
//		&& groomsmen.invitedToTheWedding("Serra", "Park")
//		&& groomsmen.invitedToTheWedding("Saadia", "Parker")
//		&& groomsmen.invitedToTheWedding("Kristin", "Livingston")
//		&& groomsmen.invitedToTheWedding("", ""));
//
//	//groomsmen.dump();
//	//bridesmaids.dump();
//
//	bridesmaids.swapWeddingGuests(groomsmen);
//	assert(bridesmaids.guestCount() == 4//tests bridemaids contains bridesmaids again
//		&& bridesmaids.invitedToTheWedding("Serra", "Park")
//		&& bridesmaids.invitedToTheWedding("Saadia", "Parker")
//		&& bridesmaids.invitedToTheWedding("Kristin", "Livingston")
//		&& bridesmaids.invitedToTheWedding("", ""));
//
//	//groomsmen.dump();
//	//bridesmaids.dump();
//	//cerr << "pass swap test" << endl;
//
//	//tests copy constructor, assignment operator
//	string first1;
//	string last1;
//	GuestType value1;
//	WeddingGuest temp = groomsmen;//cpy constructor
//	assert(groomsmen.verifyGuestOnTheList(0, first, last, value) == temp.verifyGuestOnTheList(0, first1, last1, value1) && groomsmen.guestCount() == temp.guestCount());
//	groomsmen = bridesmaids;//assignment operator
//	assert(groomsmen.verifyGuestOnTheList(0, first, last, value) == bridesmaids.verifyGuestOnTheList(0, first1, last1, value1) && groomsmen.guestCount() == bridesmaids.guestCount());
//	groomsmen = temp;
//	//cerr << "pass constructor and assignment operator" << endl;
//
//	bridesmaids.inviteGuest("Tony", "Ambrosio", "0");
//
//	//tests matchInvitedGuest && alterGuest
//	assert(bridesmaids.alterGuest("Tony", "Ambrosio", "43") && bridesmaids.matchInvitedGuest("Tony", "Ambrosio", value) && value == "43");//tests when guest is on list
//	assert(!bridesmaids.alterGuest("Cynthia", "Nguyen", "20"));//tests when guest is not on list
//
//	//test inviteOrAlter
//	assert(bridesmaids.inviteOrAlter("Cynthia", "Nguyen", "19") && bridesmaids.guestCount() == 6);//test invited when not on list
//	assert(bridesmaids.inviteOrAlter("Tony", "Ambrosio", "60") && bridesmaids.matchInvitedGuest("Tony", "Ambrosio", value) && value == "60" && bridesmaids.guestCount() == 6);//test alters when guest is on list
//
//	//tests nonmember functions//
//
//	//tests joinGuests
//	WeddingGuest test1;
//	joinGuests(groomsmen, bridesmaids, test1);//odJined is empty
//	joinGuests(groomsmen, bridesmaids, temp);//odJoined containes values
//	assert(test1.verifyGuestOnTheList(0, first, last, value) == temp.verifyGuestOnTheList(0, first1, last1, value1) && test1.guestCount() == temp.guestCount());
//
//	attestGuests("*", "*", test1, temp);//both first and last are wild
//	//temp.dump();
//
//	WeddingGuest test2;
//	WeddingGuest test2_1;
//	test2.inviteGuest("Anthony", "Nguyen", "18");
//	test2.inviteGuest("Cynthia", "Nguyen", "19");
//	test2.inviteGuest("Phuong", "Tran", "76");
//	test2.inviteGuest("Khanh", "Nguyen", "64");
//	test2.inviteGuest("Kelvin", "Thoi", "23");
//	test2.inviteGuest("Cynthia", "Tran", "19");
//
//	attestGuests("*", "Nguyen", test2, temp);//test only first is wild and odResult is not empty
//	attestGuests("*", "Nguyen", test2, test2_1);//test only first is wild and odResult is empty
//	//temp.dump()
//	//test2_1.dump()
//	assert(temp.guestCount() == test2_1.guestCount());
//	assert(test2_1.guestCount() == 3);
//
//	attestGuests("Cynthia", "*", test2, temp);//test only last is wild
//	assert(temp.guestCount() == 2);
//
//	attestGuests("Cynthia", "*", test2, test2);//tests if both odOne and odResults are same linked list
//	assert(test2.guestCount() == 2 && test2.invitedToTheWedding("Cynthia", "Nguyen") && test2.invitedToTheWedding("Cynthia", "Tran"));
//
//	return;
//}
//int main() {
//	teststring();
//	cout << "Passed all tests" << endl;
//	return 0;
//}

#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <cassert> 
#include <vector> 
#include <type_traits> 
#include "WeddingGuest.h" 

using namespace std;

bool matchInvitedGuest3type(bool (WeddingGuest::*)(const
    std::string&, const std::string&, GuestType&) const) {
    return
        true;
}
bool matchInvitedGuest3type(bool (WeddingGuest::*)(const
    std::string&, const std::string&, GuestType&)) {
    return false;
}
bool matchInvitedGuest3type(...) { return false; }
bool verifyGuestOnTheList4type(bool (WeddingGuest::*)(int,
    std::string&, std::string&, GuestType&) const) {
    return true;
}
bool verifyGuestOnTheList4type(bool (WeddingGuest::*)(int,
    std::string&, std::string&, GuestType&)) {
    return false;
}
bool verifyGuestOnTheList4type(...) { return false; }

std::string SOMEFNAME = std::string("123");
std::string DEFAULTFNAME = std::string();
std::string ARRAYFNAME[6] = {
 std::string("10"), std::string("20"), std::string("30"),
 std::string("40"), std::string("50"), std::string("60")
};

std::string SOMELNAME = std::string("321");
std::string DEFAULTLNAME = std::string();
std::string ARRAYLNAME[6] = {
 std::string("11"), std::string("21"), std::string("31"),
 std::string("41"), std::string("51"), std::string("61")
};

GuestType SOMEVALUE = "junk";

GuestType DEFAULTV = GuestType();
GuestType ARRAYV[6] = {
 "able", "baker", "charlie", "delta", "echo", "foxtrot"
};

bool has(const WeddingGuest& m, const std::string& firstName,
    const std::string& lastName, const GuestType& v)
{
    GuestType v2 = DEFAULTV;
    m.matchInvitedGuest(firstName, lastName, v2);
    GuestType v3 = SOMEVALUE;
    m.matchInvitedGuest(firstName, lastName, v3);
    return v2 == v && v3 == v;
}

void testone(int n)
{
    WeddingGuest m;
    switch (n)
    {
    default: {
        cout << "Bad argument" << endl;
    } break; case  1: {
        assert((is_same<decltype(&WeddingGuest::noGuests),
            bool (WeddingGuest::*)() const>::value));
    } break; case  2: {
        assert((is_same<decltype(&WeddingGuest::guestCount),
            int (WeddingGuest::*)() const>::value));
    } break; case  3: {

        assert((is_same<decltype(&WeddingGuest::invitedToTheWedding), bool (WeddingGuest::*)(const std::string, const std::string)
            const>::value) ||

            (is_same<decltype(&WeddingGuest::invitedToTheWedding),
                bool (WeddingGuest::*)(const std::string&, const std::string&)
                const>::value));
    } break; case  4: {

        assert(matchInvitedGuest3type(&WeddingGuest::matchInvitedGuest));
    } break; case  5: {

        assert(verifyGuestOnTheList4type(&WeddingGuest::verifyGuestOnTheList));
    } break; case  6: {
        assert(m.noGuests());
    } break; case  7: {
        assert(m.guestCount() == 0);
    } break; case  8: {
            assert(!m.alterGuest(DEFAULTFNAME, DEFAULTLNAME,
                SOMEVALUE) && m.guestCount() == 0);
        } break; case  9: {
        assert(!m.crossGuestOff(DEFAULTFNAME, DEFAULTLNAME)
            && m.guestCount() == 0);
    } break; case 10: {
            assert(!m.invitedToTheWedding(DEFAULTFNAME,
                DEFAULTLNAME));
        } break; case 11: {
        GuestType v = SOMEVALUE;
        assert(!m.matchInvitedGuest(DEFAULTFNAME,
            DEFAULTLNAME, v) && v == SOMEVALUE);
    } break; case 12: {
            GuestType v = SOMEVALUE;
            assert(!m.verifyGuestOnTheList(0, DEFAULTFNAME,
                DEFAULTLNAME, v) && v == SOMEVALUE);
        } break; case 13: {
        assert(m.inviteGuest(SOMEFNAME, SOMELNAME,
            SOMEVALUE));
    } break; case 14: {
            m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
            assert(!m.noGuests());
        } break; case 15: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        assert(m.guestCount() == 1);
    } break; case 16: {
            m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
            assert(m.invitedToTheWedding(SOMEFNAME, SOMELNAME));
        } break; case 17: {
        m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
        GuestType v = DEFAULTV;
        assert(m.matchInvitedGuest(SOMEFNAME, SOMELNAME,
            v));
    } break; case 18: {
            m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
            GuestType v = DEFAULTV;
            m.matchInvitedGuest(SOMEFNAME, SOMELNAME, v);
            assert(v == SOMEVALUE);
        } break; case 19: {
        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
            SOMEVALUE);
        GuestType v = DEFAULTV;
        assert(!m.matchInvitedGuest(ARRAYFNAME[1],
            ARRAYLNAME[1], v));
    } break; case 20: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            GuestType v = SOMEVALUE;
            m.matchInvitedGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                v);
            assert(v == SOMEVALUE);
        } break; case 21: {
            m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
            std::string f = DEFAULTFNAME;
            std::string l = DEFAULTLNAME;
            GuestType v = DEFAULTV;
            assert(m.verifyGuestOnTheList(0, f, l, v));
        } break; case 22: {
            m.inviteGuest(SOMEFNAME, SOMELNAME, SOMEVALUE);
            std::string f = DEFAULTFNAME;
            std::string l = DEFAULTLNAME;
            GuestType v = DEFAULTV;
            m.verifyGuestOnTheList(0, f, l, v);
            assert(f == SOMEFNAME && l == SOMELNAME && v ==
                SOMEVALUE);
        } break; case 23: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            assert(!m.noGuests() && m.guestCount() == 2);
        } break; case 24: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            assert(m.invitedToTheWedding(ARRAYFNAME[0],
                ARRAYLNAME[0]) && m.invitedToTheWedding(ARRAYFNAME[1],
                    ARRAYLNAME[1]));
        } break; case 25: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));

        } break; case 26: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                SOMEVALUE);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                SOMEVALUE);
                assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
                    SOMEVALUE) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
        } break; case 27: {
            assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]));
            assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]));
        } break; case 28: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[2]);
            assert(m.guestCount() == 2);
        } break; case 29: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[2]);
            assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
        } break; case 30: {
            assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]));
            assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]));
            assert(!m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[2]));
        } break; case 31: {
            assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]));
            assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]));
            assert(!m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]));
        } break; case 32: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[2]);
            m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                SOMEVALUE);
                assert(m.guestCount() == 3 &&
                    m.invitedToTheWedding(ARRAYFNAME[0], ARRAYLNAME[0]) &&
                    m.invitedToTheWedding(ARRAYFNAME[1],
                        ARRAYLNAME[1]) && m.invitedToTheWedding(ARRAYFNAME[2],
                            ARRAYLNAME[2]));
        } break; case 33: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[2]);
            m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                SOMEVALUE);
            assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE) &&
                has(m, ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]));
        } break; case 34: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[2]);
            assert(m.alterGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                SOMEVALUE));
        } break; case 35: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.alterGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[0]);
            assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0],
                ARRAYLNAME[0], ARRAYV[0]) &&
                has(m, ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]) && !m.invitedToTheWedding(ARRAYFNAME[2],
                        ARRAYLNAME[2]));
        } break; case 36: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            assert(!m.alterGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[2]) && !m.alterGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                    ARRAYV[0]));
        } break; case 37: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            assert(!m.noGuests() && m.guestCount() == 2);
        } break; case 38: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
            } break; case 39: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                SOMEVALUE);
            m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1],
                SOMEVALUE);
            assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
                SOMEVALUE) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
        } break; case 40: {
                assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]));
                assert(m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]));
            } break; case 41: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteOrAlter(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[2]);
            assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0],
                ARRAYLNAME[0], ARRAYV[2]) &&
                has(m, ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]));
        } break; case 42: {
                assert(m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]));
                assert(m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]));
                assert(m.inviteOrAlter(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[2]));
            } break; case 43: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[2]);
            m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1],
                SOMEVALUE);
            assert(m.guestCount() == 3 && has(m, ARRAYFNAME[0],
                ARRAYLNAME[0], ARRAYV[0]) &&
                has(m, ARRAYFNAME[1], ARRAYLNAME[1],
                    SOMEVALUE) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
        } break; case 44: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]);
                assert(m.inviteOrAlter(ARRAYFNAME[1], ARRAYLNAME[1],
                    SOMEVALUE));
            } break; case 45: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteOrAlter(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[0]);
            assert(m.guestCount() == 3 && has(m, ARRAYFNAME[0],
                ARRAYLNAME[0], ARRAYV[0]) &&
                has(m, ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]));
        } break; case 46: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                assert(m.inviteOrAlter(ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]));
            } break; case 47: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            assert(m.crossGuestOff(ARRAYFNAME[1],
                ARRAYLNAME[1]));
        } break; case 48: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
                assert(!m.noGuests() && m.guestCount() == 1 &&
                    has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
                    !m.invitedToTheWedding(ARRAYFNAME[1],
                        ARRAYLNAME[1]));
            } break; case 49: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
            assert(!m.noGuests() && m.guestCount() == 1 &&
                has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) &&
                !m.invitedToTheWedding(ARRAYFNAME[0],
                    ARRAYLNAME[0]));
        } break; case 50: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                m.crossGuestOff(ARRAYFNAME[0], ARRAYLNAME[0]);
                m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
                assert(m.guestCount() == 0);
            } break; case 51: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[2]);
            m.crossGuestOff(ARRAYFNAME[1], ARRAYLNAME[1]);
            m.crossGuestOff(ARRAYFNAME[2], ARRAYLNAME[2]);
            m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                ARRAYV[3]);
            assert(m.guestCount() == 2 && has(m, ARRAYFNAME[0],
                ARRAYLNAME[0], ARRAYV[0]) &&
                has(m, ARRAYFNAME[3], ARRAYLNAME[3],
                    ARRAYV[3]) && !m.invitedToTheWedding(ARRAYFNAME[1],
                        ARRAYLNAME[1]) &&
                !m.invitedToTheWedding(ARRAYFNAME[2],
                    ARRAYLNAME[2]));
        } break; case 52: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                assert(!m.crossGuestOff(ARRAYFNAME[2],
                    ARRAYLNAME[2]) && m.guestCount() == 2);
            } break; case 53: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            std::string f;
            std::string l;
            GuestType v;
            assert(!m.verifyGuestOnTheList(-1, f, l, v));
        } break; case 54: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                std::string f = SOMEFNAME;
                std::string l = SOMELNAME;
                GuestType v = SOMEVALUE;
                m.verifyGuestOnTheList(-1, f, l, v);
                assert(f == SOMEFNAME && l == SOMELNAME && v ==
                    SOMEVALUE);
            } break; case 55: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            std::string f, l;
            GuestType v;
            assert(!m.verifyGuestOnTheList(2, f, l, v));
        } break; case 56: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                std::string f = SOMEFNAME;
                std::string l = SOMELNAME;
                GuestType v = SOMEVALUE;
                m.verifyGuestOnTheList(2, f, l, v);
                assert(f == SOMEFNAME && l == SOMELNAME && v ==
                    SOMEVALUE);
            } break; case 57: {
            m.inviteGuest(DEFAULTFNAME, DEFAULTLNAME,
                SOMEVALUE);
                assert(m.guestCount() == 1 && has(m, DEFAULTFNAME,
                    DEFAULTLNAME, SOMEVALUE));
        } break; case 58: {
                m.alterGuest(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
                assert(m.guestCount() == 0 &&
                    !m.invitedToTheWedding(DEFAULTFNAME, DEFAULTLNAME));
            } break; case 59: {
            m.inviteOrAlter(DEFAULTFNAME, DEFAULTLNAME,
                SOMEVALUE);
            assert(m.guestCount() == 1 && has(m, DEFAULTFNAME,
                DEFAULTLNAME, SOMEVALUE));
        } break; case 60: {
                m.inviteGuest(DEFAULTFNAME, DEFAULTLNAME,
                    SOMEVALUE);
                m.crossGuestOff(DEFAULTFNAME, DEFAULTLNAME);
                assert(m.guestCount() == 0 &&
                    !m.invitedToTheWedding(DEFAULTFNAME, DEFAULTLNAME));
            } break; case 61: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            {
                WeddingGuest m2;
                m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]);
                m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                    ARRAYV[3]);
                m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                m.swapWeddingGuests(m2);
                assert(m.guestCount() == 3);
            }
        } break; case 62: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                {
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);
                    m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m.swapWeddingGuests(m2);
                        assert(has(m, ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) &&
                            has(m, ARRAYFNAME[3], ARRAYLNAME[3],
                                ARRAYV[3]) && !m.invitedToTheWedding(ARRAYFNAME[0],
                                    ARRAYLNAME[0]));
                }
            } break; case 63: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                ARRAYV[1]);
            {
                WeddingGuest m2;
                m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]);
                m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                    ARRAYV[3]);
                m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                m.swapWeddingGuests(m2);
                assert(m2.guestCount() == 2);
            }
        } break; case 64: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                {
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);
                    m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m.swapWeddingGuests(m2);
                    assert(has(m2, ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]) && has(m2, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1])
                        &&
                        !m2.invitedToTheWedding(ARRAYFNAME[2],
                            ARRAYLNAME[2]) && !m2.invitedToTheWedding(ARRAYFNAME[3],
                                ARRAYLNAME[3]));
                }
            } break; case 65: {
            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                ARRAYV[2]);
            m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                ARRAYV[3]);
            m.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                ARRAYV[4]);
            {
                WeddingGuest m2;
                m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                    ARRAYV[3]);
                m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                    ARRAYV[4]);
                m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.swapWeddingGuests(m2);
                assert(m.guestCount() == 3 && m2.guestCount()
                    == 5);
            }
        } break; case 66: {
            {
                WeddingGuest m2;
                m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                assert(m2.guestCount() == 2 &&
                    m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                    !m2.invitedToTheWedding(ARRAYFNAME[2], ARRAYLNAME[3]));
            }
            } break; case 67: {
                {
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    m2.crossGuestOff(ARRAYFNAME[1],
                        ARRAYLNAME[1]);
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);
                    m2.crossGuestOff(ARRAYFNAME[2],
                        ARRAYLNAME[2]);
                        m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                    m2.crossGuestOff(ARRAYFNAME[0],
                        ARRAYLNAME[0]);
                    m2.crossGuestOff(ARRAYFNAME[3],
                        ARRAYLNAME[3]);
                    m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                        ARRAYV[4]);
                }
                assert(true);  // no corruption so bad that destruction failed
        } break; case 68: {
            {
                WeddingGuest m2;
                m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                WeddingGuest m3(m2);
                m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]);
                m3.crossGuestOff(ARRAYFNAME[1],
                    ARRAYLNAME[1]);
                m3.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                    ARRAYV[3]);
                m3.crossGuestOff(ARRAYFNAME[2],
                    ARRAYLNAME[2]);
                m3.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                m3.crossGuestOff(ARRAYFNAME[0],
                    ARRAYLNAME[0]);
                m3.crossGuestOff(ARRAYFNAME[3],
                    ARRAYLNAME[3]);
                m3.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                    ARRAYV[4]);
            }
            assert(true);  // no corruption so bad that destruction failed
            } break; case 69: {
                {
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                        WeddingGuest m3(m2);
                    assert(m3.guestCount() == 3);
                }
                } break; case 70: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]);
                {
                    WeddingGuest m2(m);
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);
                    assert(m2.guestCount() == m.guestCount() +
                        1);
                }
            } break; case 71: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    {
                        WeddingGuest m2(m);
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        assert(m2.guestCount() == 4 &&
                            m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[3], ARRAYLNAME[3]));
                    }
                } break; case 72: {
                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                    ARRAYV[0]);
                m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                    ARRAYV[1]);
                m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                    ARRAYV[2]);
                {
                    WeddingGuest m2(m);
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);
                    assert(m2.guestCount() == 4 &&
                        m2.invitedToTheWedding(ARRAYFNAME[1], ARRAYLNAME[1]) &&
                        !m2.invitedToTheWedding(ARRAYFNAME[4], ARRAYLNAME[4]));
                }
            } break; case 73: {
                {
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    WeddingGuest m3;
                    m3.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                        ARRAYV[4]);
                    m3.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5],
                        ARRAYV[5]);
                    m3 = m2;
                    assert(m3.guestCount() == 3 &&
                        m2.guestCount() == 3);
                }
                } break; case 74: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    {
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                            ARRAYV[4]);
                        m2 = m;
                        m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5],
                            ARRAYV[5]);
                        assert(m2.guestCount() == m.guestCount() +
                            1);
                    }
                } break; case 75: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    {
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                            m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                                ARRAYV[4]);
                        m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5],
                            ARRAYV[5]);
                        m2 = m;
                        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        assert(m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]) &&
                            !m2.invitedToTheWedding(ARRAYFNAME[3],
                                ARRAYLNAME[3]));
                    }
                } break; case 76: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    {
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                            ARRAYV[4]);
                        m2.inviteGuest(ARRAYFNAME[5], ARRAYLNAME[5],
                            ARRAYV[5]);
                        m2 = m;
                        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        assert(m.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            !m.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]));
                    }
                } break; case 77: {
                    {
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                            m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                                ARRAYV[2]);
                        m2 = m2;
                        assert(m2.guestCount() == 3);
                        assert(m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]));
                    }
                    assert(true);  // no corruption so bad that destruction failed
                } break; case 78: {
                    {
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m2.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        m2 = m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        assert(m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[3],
                                ARRAYLNAME[3]));
                    }
                } break; case 79: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        WeddingGuest m3;
                        joinGuests(m, m2, m3);
                        assert(m3.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]));
                    } break; case 80: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    WeddingGuest m2;
                    WeddingGuest m3;
                    joinGuests(m2, m, m3);
                    assert(m3.invitedToTheWedding(ARRAYFNAME[0],
                        ARRAYLNAME[0]) &&
                        m3.invitedToTheWedding(ARRAYFNAME[1],
                            ARRAYLNAME[1]) &&
                        m3.invitedToTheWedding(ARRAYFNAME[2],
                            ARRAYLNAME[2]));
                } break; case 81: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                            ARRAYV[4]);
                        WeddingGuest m3;
                        joinGuests(m, m2, m3);
                        assert(m3.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[3],
                                ARRAYLNAME[3]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[4],
                                ARRAYLNAME[4]));
                    } break; case 82: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                    m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);
                    m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                        ARRAYV[4]);
                    WeddingGuest m3;
                    assert(joinGuests(m, m2, m3));
                } break; case 83: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                            ARRAYV[4]);
                        WeddingGuest m3;
                        m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[5]);
                        joinGuests(m, m2, m3);
                        assert(m3.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[3],
                                ARRAYLNAME[3]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[4],
                                ARRAYLNAME[4]) &&
                            has(m3, ARRAYFNAME[2], ARRAYLNAME[2],
                                ARRAYV[2]) &&
                            !has(m3, ARRAYFNAME[2], ARRAYLNAME[2],
                                ARRAYV[5]));
                    } break; case 84: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);
                    m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                        ARRAYV[4]);
                    WeddingGuest m3;
                    m3.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[5]);
                    assert(joinGuests(m, m2, m3));
                } break; case 85: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m3;
                        joinGuests(m, m2, m3);
                        assert(m3.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[3],
                                ARRAYLNAME[3]));
                    } break; case 86: {
                    m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                        ARRAYV[0]);
                    m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                        ARRAYV[1]);
                    m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    WeddingGuest m2;
                    m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                        ARRAYV[3]);

                    m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                        ARRAYV[2]);
                    WeddingGuest m3;
                    assert(joinGuests(m, m2, m3));
                } break; case 87: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[4]);
                        WeddingGuest m3;
                        joinGuests(m, m2, m3);
                        assert(m3.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m3.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]));
                    } break; case 88: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[4]);
                        WeddingGuest m3;
                        assert(!joinGuests(m, m2, m3));
                    } break; case 89: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                            ARRAYV[4]);
                        joinGuests(m, m2, m);
                            assert(m.invitedToTheWedding(ARRAYFNAME[0],
                                ARRAYLNAME[0]) &&
                                m.invitedToTheWedding(ARRAYFNAME[1],
                                    ARRAYLNAME[1]) &&
                                m.invitedToTheWedding(ARRAYFNAME[2],
                                    ARRAYLNAME[2]) &&
                                m.invitedToTheWedding(ARRAYFNAME[3],
                                    ARRAYLNAME[3]) &&
                                m.invitedToTheWedding(ARRAYFNAME[4],
                                    ARRAYLNAME[4]));
                    } break; case 90: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[3], ARRAYLNAME[3],
                            ARRAYV[3]);
                        m2.inviteGuest(ARRAYFNAME[4], ARRAYLNAME[4],
                            ARRAYV[4]);
                        joinGuests(m, m2, m2);
                        assert(m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[3],
                                ARRAYLNAME[3]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[4],
                                ARRAYLNAME[4]));
                    } break; case 91: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        m2.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m2);
                        assert(!m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) && m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]));
                    } break; case 92: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m2);
                        assert(!m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[0]) && m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]));
                    } break; case 93: {
                            m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                                ARRAYV[0]);
                            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                                ARRAYV[1]);
                            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                                ARRAYV[2]);
                            attestGuests(ARRAYFNAME[1], ARRAYLNAME[1], m, m);
                            assert(!m.invitedToTheWedding(ARRAYFNAME[0],
                                ARRAYLNAME[0]) && m.invitedToTheWedding(ARRAYFNAME[1],
                                    ARRAYLNAME[1]));
                        } break; case 94: {
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[2]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[1],
                            ARRAYV[3]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        attestGuests("*", ARRAYLNAME[1], m, m2);
                        assert(m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[1]) &&
                            !m2.invitedToTheWedding(ARRAYFNAME[0],
                                ARRAYLNAME[0]) &&
                            !m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]));
                    } break; case 95: {
                                m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                                    ARRAYV[0]);
                            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[0],
                                ARRAYV[1]);
                            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                                ARRAYV[2]);
                            m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[2],
                                ARRAYV[3]);
                            m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                                ARRAYV[2]);
                            WeddingGuest m2;
                            attestGuests(ARRAYFNAME[1], "*", m, m2);
                            assert(m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[0]) &&
                                m2.invitedToTheWedding(ARRAYFNAME[1],
                                    ARRAYLNAME[1]) &&
                                m2.invitedToTheWedding(ARRAYFNAME[1],
                                    ARRAYLNAME[2]) &&
                                !m2.invitedToTheWedding(ARRAYFNAME[0],
                                    ARRAYLNAME[0]) &&
                                !m2.invitedToTheWedding(ARRAYFNAME[2],
                                    ARRAYLNAME[2]));
                        } break; case 96: {
                        string all = "*";
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[0],
                            ARRAYV[0]);
                        m.inviteGuest(ARRAYFNAME[0], ARRAYLNAME[1],
                            ARRAYV[1]);
                        m.inviteGuest(ARRAYFNAME[1], ARRAYLNAME[1],
                            ARRAYV[2]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[1],
                            ARRAYV[3]);
                        m.inviteGuest(ARRAYFNAME[2], ARRAYLNAME[2],
                            ARRAYV[2]);
                        WeddingGuest m2;
                        attestGuests("*", "*", m, m2);
                        assert(m2.invitedToTheWedding(ARRAYFNAME[0],
                            ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[1],
                                ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[1]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[0],
                                ARRAYLNAME[0]) &&
                            m2.invitedToTheWedding(ARRAYFNAME[2],
                                ARRAYLNAME[2]));
                    } break; case 97: {
                                WeddingGuest m2 = m;
                            WeddingGuest m3;
                            attestGuests("*", "*", m2, m3);
                            assert(m3.guestCount() == m.guestCount());
                        } break; case 98: {
                        WeddingGuest m2;
                        WeddingGuest m3(m);
                        attestGuests("*", "*", m2, m3);
                        assert(m3.noGuests());
                    } break; case 99: {
                            WeddingGuest m2;
                            attestGuests("*", "*", m2, m2);
                            assert(m2.guestCount() == 0);
                        } break; case 100: {
                        const int NITEMS = 2000;
                        for (int k = 0; k < NITEMS; k++)
                            assert(m.inviteGuest(std::to_string(k),
                                std::to_string(k), SOMEVALUE));
                        assert(m.guestCount() == NITEMS);
                    }
    }
}

int main()
{
    for (int n = 1; n <= 100; n++) {
        testone(n);
        cout << n << " passed" << endl;
    }

    return 0;
}

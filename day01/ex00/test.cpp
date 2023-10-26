struct Child {};

struct Owner {

	Child child;

};

struct Thief {

	Child *child;

};

int main() {
	Owner owner;

	Thief thief;
	thief.child = &owner.child;

	return 0;
}
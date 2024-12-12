



Constructor: ClassName::ClassName(Args);
Destructor: ClassName::~ClassName();

ClassName &ClassName::operator=(const ClassName &ref) {}

<return_type> ClassName::<function_name>(<parameters>) [qualifiers] [noexcept];
void Warlock::introduce() const {}
const std::string& Warlock::getName() const {}



pure method: virtual e =0
Also add a clone pure method that returns a pointer to ASpell:
virtual ASpell* clone() const = 0;


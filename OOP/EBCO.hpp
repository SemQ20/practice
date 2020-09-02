#ifndef EBCO_HPP
#define EBCO_HPP

/* Empty Base Class Optimization */

template<typename Base, typename Member>
class BaseMemberPair : Base {
    Member mem;
public:
    BaseMemberPair(Base const& b, Member const& m) 
        : Base(b), Member(m) {}

    Base const& base() const{
        return static_cast<Base const&>(*this);
    }

    Base& base(){
        return static_cast<Base&>(*this);
    }

    Member const& member() const{
        return this->mem;
    }

    Member& member(){
        return this->mem;
    }
};

template<typename CustomClass>
class Optimizable{
    BaseMemberPair<CustomClass, void*> info_and_storage;
public:
    explicit Optimizable<CustomClass>() {}
    CustomClass get(){
        return info_and_storage.base();
    }
};

#endif
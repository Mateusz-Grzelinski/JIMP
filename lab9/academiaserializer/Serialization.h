//
// Created by mat on 04.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <Student.h>
#include <string>
#include <functional>
#include <vector>
#include <ostream>

namespace academia {
    class Serializable;

    class Serializer {
    public:
        Serializer(std::ostream *out_) : out_(out_) {}

        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

    protected:
        std::ostream *out_;
    };


    class Serializable {
    public:
        virtual void Serialize(Serializer *sss) const =0;
    };

    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(std::ostream *out_);

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class Room : public Serializable {
    public:
        void Serialize(Serializer *sss) const override;

        enum class Type {
            COMPUTER_LAB, LECTURE_HALL, CLASSROOM
        };

        Room(int id, const string name, Type type) : id_(id), name_(name), type_(type) {}

    private:
        std::string name_;
        Room::Type type_;
        int id_;
    };

    class Building : public Serializable{
    public:
        Building(int id_, const string &name_, const std::vector<Room> &rooms);
        void Serialize(Serializer *sss) const override;
    private:
        int id_;
        std::string name_;
        std::vector<Room> rooms_;
    };


}
#endif //JIMP_EXERCISES_SERIALIZATION_H

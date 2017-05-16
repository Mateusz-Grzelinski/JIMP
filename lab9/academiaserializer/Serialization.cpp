//
// Created by mat on 04.05.17.
//

#include "Serialization.h"

namespace academia {
    void Room::Serialize(Serializer *in) const {
        in->Header("room");
        in->IntegerField("id", id_);
        in->StringField("name", name_);
        in->StringField("type", TypeToString());
        in->Footer("room");
    }
    std::string Room::TypeToString() const {
        switch (type_) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }


    XmlSerializer::XmlSerializer(std::ostream *out_) : Serializer(out_) {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << std::to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" << field_name << ">" << std::to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_ << "<" << field_name << ">" << std::to_string(value) << "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "<" << field_name << ">" << "<\\" << field_name << ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";
        for (const Serializable &i: value) { i.Serialize(this); }
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Header(const std::string &object_name) { *out_ << "<" << object_name << ">"; }

    void XmlSerializer::Footer(const std::string &object_name) { *out_ << "<\\" << object_name << ">"; }

    //JSON SERIALIZER
    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "\"" << field_name << "\": " << std::to_string(value) << ", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "\"" << field_name << "\": " << std::to_string(value) << ", ";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "\"" << field_name << "\": \"" << value << "\"";
        if (field_name != "type") *out_ << ", ";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_ << "\"" << field_name << "\": " << std::to_string(value) << ", ";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << field_name;
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "\"" << field_name << "\": [";
        bool first = true;

        for (const Serializable &i: value) {
            if (!first) *out_ << ", ";
            else first = false;
            i.Serialize(this);
        }
        *out_ << "]";
    }

    void JsonSerializer::Header(const std::string &object_name) { *out_ << "{"; }

    void JsonSerializer::Footer(const std::string &object_name) { *out_ << "}"; }

    void Building::Serialize(Serializer *sss) const {
        sss->Header("building");
        sss->IntegerField("id", id_);
        sss->StringField("name", name_);
        std::vector<std::reference_wrapper<const Serializable>> wrapper;
        for (auto &it : rooms_) {
            wrapper.emplace_back(it);
        }
        sss->ArrayField("rooms", wrapper  );
        sss->Footer("building");
    }

    Building::Building(int id_, const string &name_, const std::vector<Room> &rooms) : id_(id_), name_(name_), rooms_(rooms) {};


}
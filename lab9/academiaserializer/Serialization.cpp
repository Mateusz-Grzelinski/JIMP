//
// Created by mat on 04.05.17.
//

#include "Serialization.h"

namespace academia {
    void Room::Serialize(Serializer *sss) const {
        sss->Header("room");
        sss->IntegerField("id_", id_);
        sss->StringField("name", name_);
//        switch{
//          case COMPUTER_LAB:
//
// }
        sss->StringField("type_", "1");
        sss->Footer("room");
    }


    XmlSerializer::XmlSerializer(std::ostream *out_) : Serializer(out_) {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        Header(field_name);
        for (const auto &item : value) {
            SerializableField(field_name, item);
        }
        Footer(field_name);
    }

    void XmlSerializer::Header(const std::string &object_name) {
        (*out_) << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        (*out_) << "<\\" << object_name << ">";
    }

    void Building::Serialize(Serializer *sss) const {
        sss->Header("building");
        sss->IntegerField("id", id_);
        sss->StringField("name", name_);
        sss->ArrayField("rooms", rooms_  );
        sss->Footer("building");
    }

    Building::Building(int id_, const string &name_, const std::vector<Room> &rooms) : id_(id_), name_(name_),
                                                                                       rooms_(rooms) {}
}
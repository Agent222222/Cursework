#pragma once


enum GType { // перераховуваний тип, для визначення типу гаджету (використовується в class Gadget)
    Phone,
    Tablet,
    Watch,
    None
};

class Gadget { // користувацький тип данних для роботи зі списком "гаджетів"

private:
    std::string caption;
    std::string company;
    GType gadget_type;
    double price;
    double size_x;
    double size_y;
    bool camera = false;
    bool GPS = false;
    bool monitor = false;

public:

    Gadget() {
        caption = "3310-basic";
        company = "nokia";
        gadget_type = GType::None;
        price = 10;
        size_x = 5;
        size_y = 10;
    }
    Gadget(std::string caption_inpt, std::string company_inpt, GType type, double price_inpt, double size_x_inpt, double size_y_inpt, bool camera_inpt, bool GPS_inpt, bool monitor_inpt) {
        caption = caption_inpt;
        company = company_inpt;
        gadget_type = type;
        price = price_inpt;
        size_x = size_x_inpt;
        size_y = size_y_inpt;
        camera = camera_inpt;
        GPS = GPS_inpt;
        monitor = monitor_inpt;
    }
    Gadget(const Gadget& other) : caption(other.caption), company(other.company), gadget_type(other.gadget_type), price(other.price), size_x(other.size_x), size_y(other.size_y), camera(other.camera), GPS(other.GPS), monitor(other.monitor) {}
    Gadget(Gadget&& other) : caption(other.caption), company(other.company), gadget_type(other.gadget_type), price(other.price), size_x(other.size_x), size_y(other.size_y), camera(other.camera), GPS(other.GPS), monitor(other.monitor) {
        other.caption = nullptr;
        other.company = nullptr;
        other.gadget_type = GType::None;
        other.price = NULL;
        other.size_x = NULL;
        other.size_y = NULL;
        other.camera = false;
        other.GPS = false;
        other.monitor = false;
    }

    Gadget& operator=(const Gadget& other) {

        this->caption = other.caption;
        this->company = other.company;
        this->gadget_type = other.gadget_type;
        this->price = other.price;
        this->size_x = other.size_x;
        this->size_y = other.size_y;
        this->camera = other.camera;
        this->GPS = other.GPS;
        this->monitor = other.monitor;

        return *this;
    }
    Gadget& operator=(Gadget&& other) noexcept {

        this->caption = other.caption;
        this->company = other.company;
        this->gadget_type = other.gadget_type;
        this->price = other.price;
        this->size_x = other.size_x;
        this->size_y = other.size_y;
        this->camera = other.camera;
        this->GPS = other.GPS;
        this->monitor = other.monitor;

        other.caption = nullptr;
        other.company = nullptr;
        other.gadget_type = GType::None;
        other.price = NULL;
        other.size_x = NULL;
        other.size_y = NULL;
        other.camera = false;
        other.GPS = false;
        other.monitor = false;

        return *this;
    }

    void SetType(GType type_inpt) { // метод для зміни типу гаджету з існуючого на (  type_inpt )
        this->gadget_type = type_inpt;
    }
    void SetAddition(const char* add_item) { // метод для зміни додаткових функцій гаджету 
        if (add_item == "camera") {
            camera = true;
        }
        else if (add_item == "GPS") {
            GPS = true;
        }
        else if (add_item == "monitor") {
            monitor = true;
        }
    }
    void SetProperties(std::string caption_inpt, std::string company_inpt, double price_inpt, double size_x_inpt, double size_y_inpt) { // метод для зміни основний властивостей гаджету 
        caption = caption_inpt;
        company = company_inpt;
        price = price_inpt;
        size_x = size_x_inpt;
        size_y = size_y_inpt;
    }

    double GetPrice()const { // гетер, для отримання ціни гаджету
        return price;
    }
    std::string GetCaption()const { // гетер, для отримання назви гаджету
        return caption;
    }
    std::string GetCompany()const { // гетер, для отримання назви компанії виробника гаджету
        return company;
    }
    std::string GetType()const { // гетер, для отримання типу гаджету
        if (gadget_type == Phone) {
            return "phone";
        }
        else if (gadget_type == Tablet) {
            return "tablet";
        }
        else if (gadget_type == Watch) {
            return "watch";
        }
    }

    String^ GetProperty(int index) const { // гетер, для отримання поля гаджету за індексом (перетвореного в тип String^)
        switch (index) {
        case 0:
            return msclr::interop::marshal_as<System::String^>(caption);
            break;

        case 1:
            return msclr::interop::marshal_as<System::String^>(company);
            break;

        case 2:
            if (gadget_type == Phone) {
                return msclr::interop::marshal_as<System::String^>("phone");
            }
            else if (gadget_type == Tablet) {
                return msclr::interop::marshal_as<System::String^>("tablet");
            }
            else if (gadget_type == Watch) {
                return msclr::interop::marshal_as<System::String^>("watch");
            }
            break;

        case 3:
            return price.ToString()+ "$";
            break;

        case 4:
            return size_x.ToString();
            break;

        case 5:
            return size_y.ToString();
            break;
        case 6:
            if (camera == true) {
                return "camera";
            }
            else {
                return " ";
            }
            break;
        case 7:
            if (GPS == true) {
                return "GPS";
            }
            else {
                return " ";
            }
            break;
        case 8:
            if (monitor == true) {
                return "monitor";
            }
            else {
                return " ";
            }
            break;

        default:
            return "";
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Gadget& polynom) {
        std::string type;
        std::string addition;
        std::string str_price = std::to_string(polynom.price);

        std::replace(str_price.begin(), str_price.end(), '.', ',');

        switch (polynom.gadget_type) {
            case Phone: {
                type = "phone";
                break;
            }
            case Tablet: {
                type = "tablet";
                break;
            }
            case Watch: {
                type = "watch";
                break;
            }
        }

        if (polynom.camera == true) {
            addition += "camera ";
        }
        
        if (polynom.GPS == true) {
            addition += "GPS ";
        }
        
        if (polynom.monitor == true) {
            addition += "monitor ";
        }
        out << polynom.caption << " " << polynom.company << " " << type << " " << str_price << " " << polynom.size_x << "*" << polynom.size_y << " " << addition << std::endl;

        return out;
    }
    
    friend std::istream& operator>>(std::istream& in, Gadget& polynom) {
         std::string type;

         in >> polynom.caption >> polynom.company >> type >> polynom.price >> polynom.size_x >> polynom.size_y >> polynom.camera >> polynom.GPS >> polynom.monitor;

         if (type == "phone") {
             polynom.gadget_type = Phone;
         }
         else if (type == "tablet") {
             polynom.gadget_type = Tablet;
         }
         else if (type == "watch") {
             polynom.gadget_type = Watch;
         }

         return in;
     }
};

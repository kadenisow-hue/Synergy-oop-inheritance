#include <iostream>
#include <string>

// Базовый класс, описывающий абстрактную модель искусственного интеллекта
class BaseAIModel {
protected:
    std::string modelName;
    double accuracy;

public:
    BaseAIModel(std::string name, double acc) : modelName(name), accuracy(acc) {}
    virtual ~BaseAIModel() {}

    // Виртуальный метод базового класса
    virtual void predict() {
        std::cout << "[Base AI] Модель " << modelName << " выполняет стандартное предсказание." << std::endl;
    }

    void displayInfo() {
        std::cout << "Модель: " << modelName << " | Базовая точность: " << accuracy * 100 << "%" << std::endl;
    }
};

// Производный класс для специализированной языковой модели (LLM)
class LargeLanguageModel : public BaseAIModel {
private:
    int contextWindow; // Специфичное поле производного класса

public:
    LargeLanguageModel(std::string name, double acc, int window) 
        : BaseAIModel(name, acc), contextWindow(window) {}

    // Переопределение (override) метода базового класса
    void predict() override {
        std::cout << "[LLM Override] Модель " << modelName << " генерирует текст с контекстным окном в " 
                  << contextWindow << " токенов." << std::endl;
    }

    // Собственный уникальный метод производного класса
    void fineTune() {
        std::cout << "[LLM Unique] Запущен процесс дообучения (Fine-Tuning) для модели " << modelName << "." << std::endl;
        accuracy += 0.02; // Увеличиваем точность после дообучения
    }
};

int main() {
    // Настройка локализации для корректного вывода кириллицы
    std::setlocale(LC_ALL, "Russian");

    std::cout << "=== Демонстрация работы базового класса ===" << std::endl;
    BaseAIModel genericModel("BasePredictor", 0.75);
    genericModel.displayInfo();
    genericModel.predict();

    std::cout << "\n=== Демонстрация работы производного класса ===" << std::endl;
    LargeLanguageModel llmModel("SynergyLLM", 0.91, 8192);
    llmModel.displayInfo();
    llmModel.predict();  // Вызов переопределенного метода
    llmModel.fineTune(); // Вызов собственного метода
    llmModel.displayInfo();

    std::cout << "\n=== Демонстрация полиморфизма через указатель ===" << std::endl;
    BaseAIModel* polymorphicPtr = &llmModel;
    polymorphicPtr->predict(); // Вызовется метод производного класса благодаря virtual

    return 0;
}

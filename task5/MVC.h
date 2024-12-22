#ifndef MVC_H
#define MVC_H

#include "UsefulFunctions.h"
#include <string>
#include <vector>
#include <QFile>
#include <QStandardItemModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;


// МОДЕЛЬ - управление с данными

// книга (продукт)
class Book {
public:
    string m_name;          // название книги
    string m_category;      // категория
    double m_rating;        // оценка
    string m_author;        // автор
    string m_date;          // дата прочтения
    long m_difficulty;        // сложность

    Book (string name, string category, double rating, string author, string date, long difficulty): m_name(name), m_category(category), m_rating(rating), m_author(author), m_date(date), m_difficulty(difficulty) {}
    virtual ~Book() = default;
};

// фэнтези (конкретный продукт)
class FantasyBook : public Book {
public:
    FantasyBook(string name, double rating, string author, string date, long difficulty): Book (name, "Фэнтези", rating, author, date, difficulty) {}
};

// хоррор (конкретный продукт)
class HorrorBook : public Book {
public:
    HorrorBook(string name, double rating, string author, string date, long difficulty): Book (name, "Ужасы", rating, author, date, difficulty) {}
};

// юмор (конкретный продукт)
class HumorBook : public Book {
public:
    HumorBook(string name, double rating, string author, string date, long difficulty): Book (name, "Юмор", rating, author, date, difficulty) {}
};

// история (конкретный продукт)
class HistoryBook : public Book {
public:
    HistoryBook(string name, double rating, string author, string date, long difficulty): Book (name, "История", rating, author, date, difficulty) {}
};

// боевик (конкретный продукт)
class ActionBook : public Book {
public:
    ActionBook(string name, double rating, string author, string date, long difficulty): Book (name, "Боевик", rating, author, date, difficulty) {}
};

// создатель книги (создатель)
class BookCreator {
public:
    virtual unique_ptr<Book> createBook(string name, string category, double rating, string author, string date, long difficulty) = 0;
    virtual ~BookCreator() = default;
};

// создатель книги про *любой жанр* (конкретный создатель)
class StandartBookCreator : public BookCreator {
public:
    unique_ptr<Book> createBook(string name, string category, double rating, string author, string date, long difficulty) override {
        return make_unique<Book>(name, category, rating, author, date, difficulty);
    }
};


// создатель книги про фэнтези (конкретный создатель)
class FantasyBookCreator : public BookCreator {
public:
    unique_ptr<Book> createBook(string name, string category, double rating, string author, string date, long difficulty) override {
        return make_unique<FantasyBook>(name, rating, author, date, difficulty);
    }
};

// создатель книги про хоррор (конкретный создатель)
class HorrorBookCreator : public BookCreator {
public:
    unique_ptr<Book> createBook(string name, string category, double rating, string author, string date, long difficulty) override {
        return make_unique<HorrorBook>(name, rating, author, date, difficulty);
    }
};

// создатель книги про юмор (конкретный создатель)
class HumorBookCreator : public BookCreator {
public:
    unique_ptr<Book> createBook(string name, string category, double rating, string author, string date, long difficulty) override {
        return make_unique<HumorBook>(name, rating, author, date, difficulty);
    }
};

// создатель исторической книги (конкретный создатель)
class HistoryBookCreator : public BookCreator {
public:
    unique_ptr<Book> createBook(string name, string category, double rating, string author, string date, long difficulty) override {
        return make_unique<HistoryBook>(name, rating, author, date, difficulty);
    }
};

// создатель книги про боевик (конкретный создатель)
class ActionBookCreator : public BookCreator {
public:
    unique_ptr<Book> createBook(string name, string category, double rating, string author, string date, long difficulty) override {
        return make_unique<ActionBook>(name, rating, author, date, difficulty);
    }
};



// модель
class MVC_Model {
private:
    vector<unique_ptr<Book>> m_books; // список книг
    map <string,int> categoriesValues { {"Фэнтези", 10}, {"Ужасы", 20}, {"Юмор", 30}, {"История", 40}, {"Боевик", 50}}; // +-ориентировочная сортировка жанров по их близости (может дополнятся) -> для рекомендаций
public:
    // деструктор
    ~MVC_Model() {}
    // возврат имени
    string getName(size_t index) { return m_books[index]->m_name; }
    // изменить имя
    void setName(size_t index, string name) { m_books[index]->m_name = name; }

    // возврат категории
    string getCategory(size_t index) { return m_books[index]->m_category; }
    // изменить категорию
    void setCategory(size_t index, string category) { m_books[index]->m_category = category; }

    // возврат оценки
    double getRating(size_t index) { return m_books[index]->m_rating; }
    // изменить оценку
    void setRating(size_t index, double rating) { m_books[index]->m_rating = rating; }

    // возврат автора
    string getAuthor(size_t index) { return m_books[index]->m_author; }
    // изменить автора
    void setAuthor(size_t index, string author) { m_books[index]->m_author = author; }

    // возврат даты прочтения
    string getDate(size_t index) { return m_books[index]->m_date; }
    // изменить дату прочтения
    void setDate(size_t index, string date) { m_books[index]->m_date = date; }

    // возврат сложности
    long getDifficulty(size_t index) { return m_books[index]->m_difficulty; }
    // изменить сложность
    void setDifficulty(size_t index, long difficulty) { m_books[index]->m_difficulty = difficulty; }

    // добавление книги (готовой)
    void addBook(unique_ptr<Book> book) {
        m_books.emplace_back(std::move(book));
    }

    // удаление книги по индексу
    void deleteBook(size_t index) {
        if (index >= 0 && index < m_books.size()) {
            m_books.erase(m_books.begin() + index);
        }
    }

    // возврат списка книг
    const vector<unique_ptr<Book>>& getBooks() const {
        return m_books;
    }

    // возврат значений для таблицы
    string getColumnStringValuesForTable(long row, long column) {
        UsefulFunctions us;
        switch (column) {
        case 0: // название
            return getName(row);
        case 1: // категория
            return getCategory(row);
        case 2: // оценка
            return us.toString(getRating(row));
        case 3: // автор
            return getAuthor(row);
        case 4: // дата прочтения
            return getDate(row);
        case 5: // сложность
            return us.toString(getDifficulty(row));
        default:
            return " ";
        }
    }

    // преобразование в формат JSON
    QJsonObject getJsonFormat(size_t index) {
        UsefulFunctions us;
        QJsonObject jsonObject;
        string name = getName(index);
        jsonObject["name"] = QString::fromStdString(getName(index));
        jsonObject["category"] = QString::fromStdString(getCategory(index));
        jsonObject["rating"] = QString::fromStdString(us.toString(getRating(index)));
        jsonObject["author"] = QString::fromStdString(getAuthor(index));
        jsonObject["date"] = QString::fromStdString(getDate(index));
        jsonObject["difficulty"] = QString::fromStdString(us.toString(getDifficulty(index)));
        return jsonObject;
    }

    // преобразование книги в числовой вектор
    vector<double> getVectorFromBook(size_t index) {
        vector<double> vec;
        vec.push_back(getRating(index)); // оценка
        vec.push_back(getDifficulty(index)); // сложность

        // категория
        if (categoriesValues.count(getCategory(index)) > 0) {
            vec.push_back(categoriesValues[getCategory(index)]);
        }
        // если не внесена категория в нашу ранжировку по близости, даем ей случайное значение (чтобы хоть что то попалось новое)
        else {
            srand(time(0));
            vec.push_back(rand() % 100);
        }
        return vec;
    }

    // вычисление косинусного сходства // https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTLYCImOXHNjpe-kWxW37DyIM9Uyfh6hMmxXw&s
    double cosSim(vector<double>& vec1, vector<double>& vec2) {
        double dot = 0.0;
        double norm1 = 0.0;
        double norm2 = 0.0;

        for (auto i=0; i<vec1.size(); i++) {
            dot += vec1[i] * vec2[i];
            norm1 += vec1[i] * vec1[i];
            norm2 += vec2[i] * vec2[i];
        }

        if (norm1 == 0.0 || norm2 == 0.0) {
            return 0.0;
        }

        return dot/(sqrt(norm1) * sqrt(norm2));
    }

    // вычисление евклидова расстояния // https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTfm4TN3hb-8-1NYuORff2oV12K5p9Ra1h55Q&s
    double evklidDist(vector<double>& vec1, vector<double>& vec2) {
        double sum = 0.0;
        for (auto i=0; i<vec1.size(); i++) {
            sum += pow(vec1[i] - vec2[i], 2);
        }
        return sqrt(sum);
    }

    // получение рекомендаций (в виде индексов книг) - для 1 книги
    vector<size_t> getRecommendBook(size_t bookIndx, int top) {
        vector<size_t> recommends; // рекомендации
        vector<double> ourVec = getVectorFromBook(bookIndx); // превращаем нашу книгу в вектор
        map<size_t, double> similarityMap;  // словарь схожести: индекс_книги - число схожести с нашей книгой

        // вычисляем сходство для всех книг
        for (auto i=0; i<m_books.size(); i++) {
            if (i == bookIndx) continue;
            vector<double> anotherVec = getVectorFromBook(i);
            double simCos = cosSim(ourVec, anotherVec); // по косинусу
            double simEvk = evklidDist(ourVec, anotherVec); // по евклиду
            similarityMap[i] = (simCos + simEvk)/2; // число схожесть
        }

        // сортируем по убыванию схожести
        vector<pair<size_t, double>> sortedSimilar(similarityMap.begin(), similarityMap.end());
        sort(sortedSimilar.begin(), sortedSimilar.end(), [](const pair<size_t, double>& a, const pair<size_t, double>& b)
             {
                 return a.second > b.second;
             });

        // возвращаем топ рекомендуемых книг
        for (auto i=0; (i<top) && (i<sortedSimilar.size()); i++) {
            recommends.push_back(sortedSimilar[i].first); // заполучаем схожую книгу
            qDebug() << "Найдена схожая книга для: " << bookIndx;
        }
        return recommends;
    }

    // определяем ВСЕ прочитанные книги и возвращаем список книг, которые надо вывести в рекомендации
    vector<size_t> getAllRecommend() {
        UsefulFunctions us;
        int top = 4; // топ 4 (можно поменять)
        vector<size_t> readed; // прочитанные
        vector<size_t> recommends; // рекомендации
        for (auto i=0; i<m_books.size(); i++) {
            // если моя функция определит это как дату, то значит юзер это прочитал, иначе это либо "Не читал" либо "Забросил" либо другой текст
            if (us.isCorrectDateFormat(getDate(i))) {
                readed.push_back(i);
            }
        }


        // получаем рекомендации для всей нашей прочитанной литературы
        for (auto i=0; i<readed.size(); i++) {
            qDebug() << "Прочитано: " << readed[i];   // DEV: список прочитанной литературы
            vector<size_t> getRec = getRecommendBook(readed[i], top);
            for (auto j=0; j<getRec.size(); j++) {
                // если книги такой ещё нету у общей рекомендации, то добавляем
                if (count(recommends.begin(), recommends.end(), getRec[j]) == 0) recommends.push_back(getRec[j]);
            }
        }
        // возвращаем общую рекомендацию
        return recommends;
    }
};

// ВИД - отображение пользователю
class MVC_View {
public:
    // возврат числа колонок
    int getColumns() {
        return 6;
    }

    // возврат (стандартной) табличной модели данных
    QStandardItemModel* getQItemModel(MVC_Model& model) {
        // cоздание модели
        QStandardItemModel *tableModel = new QStandardItemModel();
        // установка заголовков столбцов
        tableModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Категория" << "Оценка" << "Автор" << "Дата прочтения" << "Сложность");
        // заполнение модели данными
        for (auto row = 0; row < model.getBooks().size(); row++) {
            for (auto column = 0; column < getColumns(); column++) {
                QStandardItem *item = new QStandardItem(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // model.getColumnStringValuesForTable(row, column)
                item->setToolTip(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // установка подсказки (для длинных значений)
                tableModel->setItem(row, column, item); // заполняем ячейку
            }
        }
        return tableModel;
    }

    // возврат (рекомендованной) табличной модели данных
    QStandardItemModel* getQItemModelRecomended(MVC_Model& model) {
        vector<size_t> rec = model.getAllRecommend();
        // cоздание модели
        QStandardItemModel *tableModel = new QStandardItemModel();
        // установка заголовков столбцов
        tableModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Категория" << "Оценка" << "Автор" << "Дата прочтения" << "Сложность");
        // заполнение модели данными
        for (auto row = 0; row < model.getBooks().size(); row++) {
            // если есть такая книга в рекомендациях, выводим
            if (count(rec.begin(), rec.end(), row) > 0) {
                for (auto column = 0; column < getColumns(); column++) {
                    QStandardItem *item = new QStandardItem(QString::fromStdString(model.getColumnStringValuesForTable(row, column)));
                    item->setToolTip(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // установка подсказки (для длинных значений)
                    tableModel->setItem(row, column, item); // заполняем ячейку
                }
            }
        }
        return tableModel;
    }
};

// КОНТРОЛЛЕР - обработка пользовательского ввода
class MVC_Controller {
private:
    MVC_Model& m_model;     // Модель (адрес)
    MVC_View& m_view;           // Вид (адрес)

public:
    // конструктор
    MVC_Controller(MVC_Model& model, MVC_View& view): m_model(model), m_view(view) {}

    // добавление книги (новой)
    void addNewBook(string name, string category, double rating, string author, string date, long difficulty) {
        UsefulFunctions us;
        unique_ptr<BookCreator> creator;
        if (QString::fromStdString(category).toLower().trimmed().contains("Фэнтези")) {
            creator = make_unique<FantasyBookCreator>();
        }
        else if (QString::fromStdString(category).toLower().trimmed().contains("Ужасы")) {
            creator = make_unique<HorrorBookCreator>();
        }
        else if (QString::fromStdString(category).toLower().trimmed().contains("Юмор")) {
            creator = make_unique<HumorBookCreator>();
        }
        else if (QString::fromStdString(category).toLower().trimmed().contains("История")) {
            creator = make_unique<HistoryBookCreator>();
        }
        else if (QString::fromStdString(category).toLower().trimmed().contains("Боевик")) {
            creator = make_unique<ActionBookCreator>();
        }
        else {
            creator = make_unique<StandartBookCreator>();
        }
        m_model.addBook(creator->createBook(name, category, rating, author, date, difficulty));

    }

    // изменение книги
    void changeBook(long index, string name, string category, double rating, string author, string date, long difficulty) {
        m_model.setName(index, name);
        m_model.setCategory(index, category);
        m_model.setRating(index, rating);
        m_model.setAuthor(index, author);
        m_model.setDate(index, date);
        m_model.setDifficulty(index, difficulty);
    }

    // удаление книг
    void deleteBook(size_t index) {
        m_model.deleteBook(index);
    }

    // очистка массива книг
    void deleteAllBooks() {
        for (auto i=0; i<m_model.getBooks().size(); i++) {
            deleteBook(i);
        }
    }

    // возврат модели
    MVC_Model& getModel() {
        return m_model;
    }

    // возврат вида
    MVC_View& getView() {
        return m_view;
    }

    // выбор типа импорта файла // Используются методы из QT (проба пера) // https://doc.qt.io/qt-6/qtextstream.html
    void Import(string path) {
        QFile file(QString::fromStdString(path));
        if (file.open(QIODevice::ReadOnly)) {
            // читаем файл
            QTextStream input(&file);
            // соотносим алгоритм по формату файла
            switch (CheckFileExtension(path)) {
            case 1: // JSON
                ImportJSON(input, file);
                break;
            default: // CSV
                ImportCSV(input, file);
                break;
            }
        }
        else {
            qDebug() << "Ошибка открытия файла.";
        }

    }

    // выбор типа экспорта файла // Используются методы из QT (проба пера) // https://doc.qt.io/qt-6/qtextstream.html
    void Export(string path) {
        QFile file(QString::fromStdString(path));
        if (file.open(QIODevice::WriteOnly) && m_model.getBooks().size() > 0) {
            QTextStream out(&file);
            // соотносим алгоритм по формату файла
            switch (CheckFileExtension(path)) {
            case 1: // JSON
                ExportJSON(out, file);
                break;
            default: // CSV
                ExportCSV(out, file);
                break;
            }

        }
        else {
            qDebug() << "Ошибка открытия файла.";
        }
    }

    // возврат формата (csv, json) на основе поступающего названия файла
    int CheckFileExtension(string& path) {
        if (QString::fromStdString(path).contains(".json")) return 1;
        else return 0;
    }

    //////////
    // ИМПОРТЫ
    //////////

    // импорт CSV
    void ImportCSV(QTextStream& input, QFile& file) {
        UsefulFunctions us;
        int i=0;
        deleteAllBooks(); // очищаем массив от старых данных
        while (!input.atEnd()) {
            QStringList values = input.readLine().split(";"); // разделяем строку по итератору
            if (!values.isEmpty() && i > 0) {
                addNewBook(values[0].toStdString(),
                           values[1].toStdString(),
                           us.toDouble(values[2].toStdString()),
                           values[3].toStdString(),
                           values[4].toStdString(),
                           us.toLong(values[5].toStdString()));

            }
            i++;
        }
        file.close();
        if (input.status() != QTextStream::Ok) {
            qDebug() << "Ошибка чтения файла.";
        }
    }

    // импорт JSON
    void ImportJSON(QTextStream& input, QFile& file) {
        UsefulFunctions us;
        QByteArray jsondata = file.readAll();
        file.close();
        QJsonDocument jsondoc (QJsonDocument::fromJson(jsondata));
        if (!jsondoc.isNull()) {
            QJsonArray jsonArray = jsondoc.array(); // получаем массив
            deleteAllBooks(); // очищаем массив от старых данных
            for (const QJsonValue &value : jsonArray) {
                if (value.isObject()) {
                    QJsonObject jsonObject = value.toObject();
                    addNewBook(jsonObject["name"].toString().toStdString(),
                               jsonObject["category"].toString().toStdString(),
                               us.toDouble(jsonObject["rating"].toString().toStdString()),
                               jsonObject["author"].toString().toStdString(),
                               jsonObject["date"].toString().toStdString(),
                               us.toLong(jsonObject["difficulty"].toString().toStdString()));
                }
            }
        }
        else {
            qDebug() << "Ошибка: Формат JSON некорректен в файле.";
        }
    }

    //////////
    // ЭКСПОРТЫ
    //////////

    // экспорт CSV
    void ExportCSV(QTextStream& out, QFile& file) {
        // записываем в файл
        out << "Название;" << "Категория;" << "Оценка;" << "Автор;" << "Дата прочтения;" << "Сложность\n";
        for (auto i=0; i<m_model.getBooks().size(); i++) {
            out << QString::fromStdString(m_model.getName(i)) << ";"
                << QString::fromStdString(m_model.getCategory(i)) << ";"
                << m_model.getRating(i) << ";"
                << QString::fromStdString(m_model.getAuthor(i)) << ";"
                << QString::fromStdString(m_model.getDate(i)) << ";"
                << m_model.getDifficulty(i) << "\n";
        }
        file.close();
        if (out.status() != QTextStream::Ok) {
            qDebug() << "Ошибка записи файла.";
        }
    }

    // экспорт JSON
    void ExportJSON(QTextStream& out, QFile& file) {
        QJsonArray jsonArray;
        for (auto i=0; i<m_model.getBooks().size(); i++) {
            jsonArray.append(m_model.getJsonFormat(i));
        }
        QJsonDocument jsonDoc(jsonArray);
        file.write(jsonDoc.toJson());
        file.close();
    }
};

#endif // MVC_H

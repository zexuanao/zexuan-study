#include <iostream>
#include <string>
#include <vector>

// 定义书评结构体
struct Review {
    std::string title;
    int rating;
};

// 填充书评信息
bool FillReview(Review & rr) {
    std::cout << "输入书名（输入 quit 退出）：";
    std::getline(std::cin, rr.title);

    if (rr.title == "quit")
        return false;

    std::cout << "输入书的评分：";
    std::cin >> rr.rating;

    if (!std::cin)
        return false;

    // 清除输入行的其余部分
    while (std::cin.get() != '\n')
        continue;

    return true;
}

// 显示书评信息
void ShowReview(const Review & rr) {
    std::cout << "评分：" << rr.rating << "\t书名：" << rr.title << std::endl;
}

int main() {
    using std::cout;
    using std::vector;

    vector<Review> books; // 存储书评的向量
    Review temp;

    // 填充书评信息直到用户输入 quit
    while (FillReview(temp))
        books.push_back(temp);

    int num = books.size();

    if (num > 0) {
        cout << "谢谢。您输入了如下书评：\n";
        cout << "评分\t书名\n";
        
        // 使用数组索引访问
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);

        cout << "重现：\n";
        
        // 使用迭代器访问
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        // 使用复制构造函数创建一个新的向量
        vector<Review> oldlist(books);

        // 如果书评数量超过 3，删除两个条目
        if (num > 3)
            books.erase(books.begin() + 1, books.begin() + 3);

        cout << "删除后：\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        // 在指定位置插入一个新的书评
        books.insert(books.begin() + 1, oldlist.begin() + 1, oldlist.begin() + 3);

        cout << "插入后：\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        // 交换两个向量
        books.swap(oldlist);

        cout << "将 oldlist 与 books 交换后：\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    } else {
        cout << "未输入任何书评，没有获得任何信息。\n";
    }

    return 0;
}

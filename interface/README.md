 Простейшее интерфейсное приложение. Использовалось исключительно для тестирования работы с CSS и простой отрисовкой в Qt.
Попытка имитации программы, визуализирующей звуковой сигнал в зависимости от настройки громкости и усиления.<br><br>
Из логики содержит только генерацию рандомного сигнала с учетом настроек громкости и усиления.
Интерфейс состоит из 2 крутилок (громкость, усиление), 2 progressBar'ов, показывающих текущие значения этих параметров, кастомного виджета-отрисовщика и кнопки.
Но нажатии кнопки генерируется "сигнал", попадающий в отрисовщик, который обозначает итоговую "громкость" столбцами разной высоты (столбцы выходят из центра как вверх, так и вниз).
За сим полезный функционал заканчивается
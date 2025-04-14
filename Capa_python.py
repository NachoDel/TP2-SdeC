import requests

# URL de la API del Banco Mundial para el Índice GINI de Argentina (2011-2020)
url = "https://api.worldbank.org/v2/en/country/AR/indicator/SI.POV.GINI?format=json&date=2005:2022"

# Hacer la solicitud a la API
response = requests.get(url)

# Verificar si la solicitud fue exitosa (código 200)
if response.status_code == 200:
    data = response.json()
    
    # Extraer los datos relevantes del JSON
    if data and len(data) > 1:
        indicadores = data[1]  # La segunda parte de la respuesta contiene los datos
        # print("Índice GINI de Argentina (2011-2020):")
        # Ordenar los años de menor a mayor
        for record in sorted(indicadores, key=lambda x: int(x["date"]), reverse=False):
            year = record["date"]
            value = record["value"] if record["value"] is not None else 0
            print(f"{year} {value}")
    else:
        print("No se encontraron datos en la API.")
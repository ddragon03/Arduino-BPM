<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>MHCode - Whatsapp - Java</title>

    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" integrity="sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z" crossorigin="anonymous">

    <style>
        #content-all {
            height: 100vh;
        }
    </style>
</head>
<body>
    <div id="content-all">
        <h1 class="bg-success p-4 text-white text-center">MENSAJES POR WHATSAPP - MHCODE</h1>

        <div class="container mb-5">
            <div class="row bg-dark mt-5 p-5 align-items-center rounded">
                <h2 class="text-center text-white mx-auto">Envía mensajes por whatsapp</h2>

                <form
                    class="col-md-10 p-5 mx-auto"
                    action="/mensajes-whatsapp/message" method="POST">
                    <div class="form-group">
                        <input
                            type="text"
                            name="number"
                            placeholder="Número de destino"
                            class="form-control"
                        />
                    </div>

                    <div class="form-group">
                        <textarea
                            name="message"
                            cols="30"
                            rows="10"
                            placeholder="Mensaje"
                            class="form-control"
                        ></textarea>
                    </div>
    
                    <div class="form-group text-right">
                        <button
                            class="btn btn-success px-5"
                        >Enviar</button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</body>
</html>

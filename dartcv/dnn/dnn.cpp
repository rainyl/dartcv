/*
    This file is originally from gocv project
    Licensed: Apache 2.0 license. Copyright (c) 2017-2021 The Hybrid Group.

    Modified by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/

#include "dartcv/dnn/dnn.h"
#include "dartcv/core/vec.hpp"
#include <cstring>
#include <vector>

// AsyncArray_New creates a new empty AsyncArray
CvStatus* cv_dnn_AsyncArray_new(AsyncArray* rval) {
    BEGIN_WRAP
    rval->ptr = new cv::AsyncArray();
    END_WRAP
}

// AsyncArray_Close deletes an existing AsyncArray
void cv_dnn_AsyncArray_close(AsyncArrayPtr a) {
    CVD_FREE(a);
}

CvStatus* cv_dnn_AsyncArray_get(AsyncArray async_out, Mat out) {
    BEGIN_WRAP
    async_out.ptr->get(CVDEREF(out));
    END_WRAP
}

CvStatus* cv_dnn_Net_forwardAsync(Net net, const char* outputName, AsyncArray* rval) {
    BEGIN_WRAP
    auto arr = net.ptr->forwardAsync();
    *rval = {&arr};
    END_WRAP
}

CvStatus* cv_dnn_Net_create(Net* rval) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net();
    END_WRAP
}
CvStatus* cv_dnn_Net_fromNet(Net net, Net* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net(CVDEREF(net));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNet(
    const char* model, const char* config, const char* framework, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net(cv_dnn::readNet(model, config, framework));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetBytes(
    const char* framework, VecUChar model, VecUChar config, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _model = vecuchar_c2cpp(model);
    auto _config = vecuchar_c2cpp(config);
    rval->ptr = new cv_dnn::Net(cv_dnn::readNet(framework, _model, _config));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromCaffe(
    const char* prototxt, const char* caffeModel, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromCaffe(prototxt, caffeModel));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromCaffeBytes(
    VecUChar prototxt, VecUChar caffeModel, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _prototxt = vecuchar_c2cpp(prototxt);
    auto _caffeModel = vecuchar_c2cpp(caffeModel);
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromCaffe(_prototxt, _caffeModel));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromTensorflow(
    const char* model, const char* config, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromTensorflow(model, config));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromTensorflowBytes(
    VecUChar model, VecUChar config, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _model = vecuchar_c2cpp(model);
    auto _config = vecuchar_c2cpp(config);
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromTensorflow(_model, _config));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromTFLite(const char* model, Net* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromTFLite(model));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromTFLiteBytes(
    VecUChar bufferModel, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr =
        new cv_dnn::Net(cv_dnn::readNetFromTFLite((char*)bufferModel.ptr, bufferModel.length));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromTorch(
    const char* model, bool isBinary, bool evaluate, Net* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromTorch(model, isBinary, evaluate));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromONNX(const char* model, Net* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromONNX(model));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_dnn_Net_readNetFromONNXBytes(VecUChar model, Net* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    auto _model = vecuchar_c2cpp(model);
    rval->ptr = new cv_dnn::Net(cv_dnn::readNetFromONNX(_model));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_dnn_Net_close(NetPtr net) {
    CVD_FREE(net);
}

CvStatus* cv_dnn_Net_blobFromImage(
    Mat image,
    Mat blob,
    double scalefactor,
    CvSize size,
    Scalar mean,
    bool swapRB,
    bool crop,
    int ddepth,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(size.width, size.height);
    cv::Scalar cm(mean.val1, mean.val2, mean.val3, mean.val4);
    cv_dnn::blobFromImage(CVDEREF(image), CVDEREF(blob), scalefactor, sz, cm, swapRB, crop, ddepth);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_blobFromImages(
    VecMat images,
    Mat blob,
    double scalefactor,
    CvSize size,
    Scalar mean,
    bool swapRB,
    bool crop,
    int ddepth,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(size.width, size.height);
    cv::Scalar cm = cv::Scalar(mean.val1, mean.val2, mean.val3, mean.val4);
    auto _images = vecmat_c2cpp(images);
    cv_dnn::blobFromImages(_images, CVDEREF(blob), scalefactor, sz, cm, swapRB, crop, ddepth);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_imagesFromBlob(Mat blob, VecMat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    std::vector<cv::Mat> imgs;
    cv_dnn::imagesFromBlob(CVDEREF(blob), imgs);
    *rval = vecmat_cpp2c(imgs);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

bool cv_dnn_Net_empty(Net net) {
    return net.ptr->empty();
}

CvStatus* cv_dnn_Net_dump(Net net, char** rval) {
    BEGIN_WRAP
    auto ss = net.ptr->dump();
    *rval = strdup(ss.c_str());
    END_WRAP
}

CvStatus* cv_dnn_Net_setInput(
    Net net, Mat blob, const char* name, double scalefactor, Scalar mean, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar _mean(mean.val1, mean.val2, mean.val3, mean.val4);
    net.ptr->setInput(CVDEREF(blob), name, scalefactor, _mean);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_forward(Net net, const char* outputName, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(net.ptr->forward(outputName));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_forwardLayers(
    Net net, VecMat* outputBlobs, VecVecChar outBlobNames, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Mat> blobs;

    auto names = vecvecchar_c2cpp_s(outBlobNames);
    net.ptr->forward(blobs, names);
    *outputBlobs = vecmat_cpp2c(blobs);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_setPreferableBackend(Net net, int backend) {
    BEGIN_WRAP
    net.ptr->setPreferableBackend(backend);
    END_WRAP
}

CvStatus* cv_dnn_Net_setPreferableTarget(Net net, int target) {
    BEGIN_WRAP
    net.ptr->setPreferableTarget(target);
    END_WRAP
}

CvStatus* cv_dnn_Net_getPerfProfile(
    Net net, int64_t* rval, VecF64* layersTimes, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<double> _layersTimes;
    *rval = net.ptr->getPerfProfile(_layersTimes);
    *layersTimes = vecdouble_cpp2c(_layersTimes);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_getUnconnectedOutLayers(Net net, VecI32* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    *rval = vecint_cpp2c(net.ptr->getUnconnectedOutLayers());
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_getLayerNames(Net net, VecVecChar* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    std::vector<cv::String> cstrs = net.ptr->getLayerNames();
    *rval = vecvecchar_cpp2c_s(cstrs);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_getInputDetails(
    Net net, VecF32* scales, VecI32* zeropoints, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<float> sc;
    std::vector<int> zp;
    net.ptr->getInputDetails(sc, zp);
    *scales = vecfloat_cpp2c(sc);
    *zeropoints = vecint_cpp2c(zp);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_getBlobChannel(
    Mat blob, int imgidx, int chnidx, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    int w = blob.ptr->size[3];
    int h = blob.ptr->size[2];
    rval->ptr = new cv::Mat(h, w, CV_32F, blob.ptr->ptr<float>(imgidx, chnidx));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_Net_getBlobSize(Mat blob, VecI32* rval) {
    BEGIN_WRAP
    auto size = blob.ptr->size;
    int* ptr = new int[size.dims()];
    memcpy(ptr, size.p, size.dims() * sizeof(int));
    *rval = {ptr, static_cast<size_t>(size.dims())};
    END_WRAP
}

CvStatus* cv_dnn_Net_getLayer(Net net, int layerid, Layer* rval) {
    BEGIN_WRAP
    rval->ptr = new cv::Ptr<cv_dnn::Layer>(net.ptr->getLayer(layerid));
    END_WRAP
}

CvStatus* cv_dnn_Layer_inputNameToIndex(Layer layer, const char* name, int* rval) {
    BEGIN_WRAP
    *rval = (CVDEREF(layer))->inputNameToIndex(name);
    END_WRAP
}

CvStatus* cv_dnn_Layer_outputNameToIndex(Layer layer, const char* name, int* rval) {
    BEGIN_WRAP
    *rval = (CVDEREF(layer))->outputNameToIndex(name);
    END_WRAP
}

CvStatus* cv_dnn_Layer_getName(Layer layer, char** rval) {
    BEGIN_WRAP
    auto ss = (CVDEREF(layer))->name;
    *rval = strdup(ss.c_str());
    END_WRAP
}

CvStatus* cv_dnn_Layer_getType(Layer layer, char** rval) {
    BEGIN_WRAP
    auto ss = (CVDEREF(layer))->type;
    *rval = strdup(ss.c_str());
    END_WRAP
}

void cv_dnn_Layer_close(LayerPtr layer) {
    layer->ptr->reset();
    CVD_FREE(layer);
}

CvStatus* cv_dnn_NMSBoxes(
    VecRect bboxes,
    VecF32 scores,
    float score_threshold,
    float nms_threshold,
    VecI32* indices,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<int> v;
    auto _bboxes = vecrect_c2cpp(bboxes);
    auto _scores = vecfloat_c2cpp(scores);
    cv_dnn::NMSBoxes(_bboxes, _scores, score_threshold, nms_threshold, v, 1.f, 0);
    *indices = vecint_cpp2c(v);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_dnn_NMSBoxes_1(
    VecRect bboxes,
    VecF32 scores,
    const float score_threshold,
    const float nms_threshold,
    VecI32* indices,
    const float eta,
    const int top_k,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<int> v;
    auto _bboxes = vecrect_c2cpp(bboxes);
    auto _scores = vecfloat_c2cpp(scores);
    cv_dnn::NMSBoxes(_bboxes, _scores, score_threshold, nms_threshold, v, eta, top_k);
    *indices = vecint_cpp2c(v);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
